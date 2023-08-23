#include <stdio.h>

// Fungsi untuk merubah satuan Waktu (HH:MM:SS) menjadi Detik
int TimeToSeconds(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

// Fungsi untuk mengkalkulasi perbedaan waktu dalam detik
int differences(int t1, int t2){
    return abs(t1 - t2);
}

// Fungsi untuk melakukan convert satuan detik menajadi Waktu (HH:MM:SS)
int createTime(int sec){
    int h,m,s;
	h = (sec/3600);
	m = (sec -(3600*h))/60;
	s = (sec -(3600*h)-(m*60));
    printf("Time difference H:M:S: = %d:%d:%d\n",h,m,s);
    return 0;
}

// Main Function
int main(){
    int t1,t2,diff,hh,mm,ss;
    t1 = TimeToSeconds(13,45,0);
    t2 = TimeToSeconds(14,30,0);
    diff = differences(t1,t2);
    printf("Time difference is %d seconds.\n",diff);
    createTime(diff);
}