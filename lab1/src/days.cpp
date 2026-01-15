#include "../include/days.h"
int days(int UpSpeed, int DownSpeed, int desiredHeight){
  if  (UpSpeed <= DownSpeed){
        return -1;
    }
  else if (desiredHeight < 0 || UpSpeed < 0 || DownSpeed < 0)
    {
        return -1;
    }
  if (desiredHeight <= UpSpeed){
        return 0;
    }
  int height = 0;
  int time = 1;
  int days_passed = 0;

  while (height < desiredHeight)
      {
          if (time == 1){
              height += UpSpeed;
              time -= 1;
              days_passed +=1;
          }
          else{
            height -= DownSpeed;
            time += 1;
       }
    }
    return days_passed;
}
