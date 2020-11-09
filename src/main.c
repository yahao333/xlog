#include <stdio.h>

#include "xlog.h"

int main(){
    //int priority = atoi( NULL == getenv( "XLOGLEVEL" ) ? "4" : getenv( "XLOGLEVEL" ) );
    //xlevel_set(priority);
    xlevel_set(7);
    LOGV("log v");
    LOGD("log d [%d]", 13);
    LOGI("log i");
    LOGW("log w");
    LOGE("log e");
    return 0;
}
