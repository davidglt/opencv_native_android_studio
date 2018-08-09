#include <jni.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace std;
using namespace cv;

int thresh = 200;

extern "C" {
void JNICALL
Java_es_dragonit_opencvnativeandroidstudio_MainActivity_salt(JNIEnv *env, jobject instance,
                                                             jlong addrRgba) {
    Mat &src = *(Mat *) addrRgba;

    cvtColor(src, src, CV_BGR2GRAY);
    Canny(src, src, thresh, thresh * 2, 3);
}
}
