#include "sfm.h"
#include "imagedir.h"


image3DSFM::image3DSFM()
{
    IMAGE_DOWNSAMPLE = 1;
    FOCAL_LENGTH = 4308;
    MIN_LANDMARK_SEEN = 3;
}
image3DSFM::image3DSFM(int image_downsample, double focal_length, int min_landmark_seen, double cx, double cy)
{
    IMAGE_DOWNSAMPLE = image_downsample;
    FOCAL_LENGTH = focal_length;
    MIN_LANDMARK_SEEN = min_landmark_seen;
    CX = cx;
    CY = cy;
}
void image3DSFM::imageMatching() {
    imageDir direktoriImage;
    IMAGES = direktoriImage.openFile();

    //Ptr<AKAZE> feature = AKAZE::create();
    Ptr<Feature2D> orb = ORB::create(MAX_FEATURES); 
    //Ptr<Feature2D> sift = SIFT::create();

    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");

    namedWindow("img", WINDOW_NORMAL);
    // Extract features
    for (auto f : IMAGES) {
        SFM_Helper::ImagePose a;
        cout << direktoriImage.IMAGE_DIR + "/" + f << endl;
        Mat img = imread(direktoriImage.IMAGE_DIR + "/" + f);
        assert(!img.empty());

        resize(img, img, img.size()/IMAGE_DOWNSAMPLE);
        a.img = img;
        cvtColor(img, img, COLOR_BGR2GRAY);
       // imshow("winnname", img);
        // waitKey(1);
        orb->detect(img, a.kp); // a.kp = vector<KeyPoint> - keypoint
        orb->compute(img, a.kp, a.desc); // a.desc = Mat desc - deskriptor 

        SFM.img_pose.emplace_back(a); // push back number image to vector
	//cout << "SFM.img_pose.size() " << SFM.img_pose.push_back(a);<< endl;

    }
    // Match features between all images
    for (size_t i=0; i < SFM.img_pose.size()-1; i++) {
        auto &img_pose_i = SFM.img_pose[i];
        for (size_t j=i+1; j < SFM.img_pose.size(); j++) {
            auto &img_pose_j = SFM.img_pose[j];
            vector<vector<DMatch>> matches;
            vector<Point2f> src, dst;
            vector<uchar> mask;
            vector<int> i_kp, j_kp;

            // 2 nearest neighbour match
            matcher->knnMatch(img_pose_i.desc, img_pose_j.desc, matches, 2);

            for (auto &m : matches) {
		//cout << "m[0].distance " << m[0].distance << endl; 
		//cout << "m[1].distance " << m[1].distance << endl; 
                if(m[0].distance < 0.7*m[1].distance) {
                    src.push_back(img_pose_i.kp[m[0].queryIdx].pt);
                    dst.push_back(img_pose_j.kp[m[0].trainIdx].pt);

                    i_kp.push_back(m[0].queryIdx);
                    j_kp.push_back(m[0].trainIdx);
                }
            }

            // Filter bad matches using fundamental matrix constraint
            
Mat fundamental_matrix = findFundamentalMat(src, dst, FM_RANSAC, 3.0, 0.99, mask);
	   
            Mat canvas = img_pose_i.img.clone();
            canvas.push_back(img_pose_j.img.clone());

            for (size_t k=0; k < mask.size(); k++) {
                if (mask[k]) {
                    img_pose_i.kp_match_idx(i_kp[k], j) = j_kp[k];
                    img_pose_j.kp_match_idx(j_kp[k], i) = i_kp[k];

                    line(canvas, src[k], dst[k] + Point2f(0, img_pose_i.img.rows), Scalar(0, 0, 255), 2);
                }
            }

            int good_matches = sum(mask)[0];
            //assert(good_matches >= 10);

            cout << "Feature matching " << i << " " << j << " ==> " << good_matches << "/" << matches.size() << endl;

            resize(canvas, canvas, canvas.size()/2);
	    cout << fundamental_matrix << endl;
            imshow("img", canvas);
            waitKey(1);
        }
    }

}

