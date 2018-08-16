#ifndef SFM_H
#define SFM_H
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include <iostream>

using namespace std;
using namespace cv;

struct SFM_Helper
{
    struct ImagePose
    {
        Mat img; // down sampled image used for display
        Mat desc; // feature descriptor
        vector<cv::KeyPoint> kp; // keypoint

        Mat T; // 4x4 pose transformation matrix
        Mat P; // 3x4 projection matrix

        // alias to clarify map usage below
        using kp_idx_t = size_t;
        using landmark_idx_t = size_t;
        using img_idx_t = size_t;

        map<kp_idx_t, std::map<img_idx_t, kp_idx_t>> kp_matches; // keypoint matches in other images
        map<kp_idx_t, landmark_idx_t> kp_landmark; // seypoint to 3d points

        // helper
        kp_idx_t& kp_match_idx(size_t kp_idx, size_t img_idx) { return kp_matches[kp_idx][img_idx]; };
        bool kp_match_exist(size_t kp_idx, size_t img_idx) { return kp_matches[kp_idx].count(img_idx) > 0; };

        landmark_idx_t& kp_3d(size_t kp_idx) { return kp_landmark[kp_idx]; }
        bool kp_3d_exist(size_t kp_idx) { return kp_landmark.count(kp_idx) > 0; }
    };

    // 3D point
    struct Landmark
    {
        cv::Point3f pt;
        int seen = 0; // how many cameras have seen this point
    };

    std::vector<ImagePose> img_pose;
    std::vector<Landmark> landmark;
};


class image3DSFM
{
private:
    int IMAGE_DOWNSAMPLE = 4;
    double FOCAL_LENGTH = 4308;
    int MIN_LANDMARK_SEEN = 3;
    const int MAX_FEATURES = 200;
    double CX;
    double CY;
    vector<string> IMAGES;
   
    SFM_Helper SFM;

public:
    image3DSFM();
    image3DSFM(int image_downsample, double focal_length, int min_landmark_seen, double cx, double cy);
    void imageMatching();
};

#endif // SFM_H
