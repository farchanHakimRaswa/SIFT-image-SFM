#include "imagedir.h"

imageDir::imageDir()
{
    /*****************/

}
void imageDir::saveFileTxt() {
    // CREATE FILE outputlist.txt

    ofstream out(fileName);
    out << list_image_file;
    out.close();
}

int imageDir::listImage(char* directory) {
    IMAGE_DIR = string(directory);
    dr = opendir(directory);
    if(dr == NULL) {
        cout << "direktori yang dimaksud tidak ada";
        return -1;
    }
    while((de = readdir(dr)) != NULL) {
        if(i >=2)
            list_image_file =  list_image_file + de->d_name + "\n";

        i++;
    }
    cout << list_image_file;
    cout << "outputlist.txt telah di buat tapi belum di sorting" << endl;
    saveFileTxt();
    closedir(dr);

    return 0;
}

int imageDir::sortList() {
    list_image_file = "";
    openFile();

    sort(names.begin(), names.end());
    for(size_t i = 0; i < names.size(); i++) {
        list_image_file = list_image_file +names[i] + '\n';
        cout << names[i] << '\n';

    }
    cout << list_image_file;
    cout << "sudah di sorting " << endl;
    saveFileTxt();

}
vector<string> imageDir::openFile() {
    ifstream in(fileName);
    if(!in.is_open()) {
        cout << "tidak bisa dibuka";
        //return 0;
    }
    while(getline(in,word))
        names.push_back(word); 

    //else cout << "Unable to open file";

    return names;
}
