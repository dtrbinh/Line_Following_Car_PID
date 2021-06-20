bool CheckParking(bool is_ready = false) {
  static bool all_ready = false;
  all_ready = is_ready;
  return all_ready;
}

int GetError() { //Get the "error" in the moving direction
  static int prev_error = 0;
  switch (HighSignalCount()) {
    case 0: {
        CheckModeSwitch();
        if (prev_error == 0) {
          return 0;
        } else if (prev_error == 8 || prev_error == 9) {
          prev_error = 9;
          return 9;
        } else if (prev_error == -8 || prev_error == -9) {
          prev_error = -9;
          return -9;
        }
        else return prev_error;
        break;
      }
    case 1: {
        if (Line[9] == true) {
  prev_error = 9;
  return 9; 
  }
  
  else if (Line[8] == true) {
  prev_error = 7;
  return 7;
  }

  else if (Line[7] == true) {
  prev_error = 5;
  return 5;
  }

  else if (Line[6] == true) {
  prev_error = 3;
  return 3;
  }

  else if (Line[5] == true) {
  prev_error = 1;
  return 1;
  }

  else if (Line[4] == true) {
  prev_error = -1;
  return -1;
  }

  else if (Line[3] == true) {
  prev_error = -3;
  return -3;
  }

  else if (Line[2] == true) {
  prev_error = -5;
  return -5;
  }

  else if (Line[1] == true) {
  prev_error = -7;
  return -7;
  }

  else if (Line[0] == true ) {
  prev_error = -9;
  return -9;
  }
  
  break;
      }
    case 2: {
  
       if ((Line[8]==1) && (Line[9]==1)) {
  prev_error = 8;
  return 8;
  }

  else if ((Line[7]==1) && (Line[8]==1)) {
  prev_error = 6;
  return 6;
  }

  else if ((Line[6]==1) && (Line[7]==1)) {
  prev_error = 4;
  return 4;
  }

  else if ((Line[5]==1) && (Line[6]==1)) {
  prev_error = 2;
  return 2;
  }

  else if ((Line[4]==1) && (Line[5]==1)) {
  prev_error = 0;
  return 0;
  }

  else if ((Line[3]==1) && (Line[4]==1)) {
  prev_error = -2;
  return -2;
  }

  else if ((Line[2]==1) && (Line[3]==1)) {
  prev_error = -4;
  return -4;
  }

  else if ((Line[1]==1) && (Line[2]==1)) {
  prev_error = -6;
  return -6;
  }

  else if ((Line[0]==1) && (Line[1]==1)) {
  prev_error = -8;
  return -8;
  }
  
  else return prev_error;
  break;
      }
    case 3: {
               if ( (Line[0]==1) && (Line[1]==1) && (Line[2]==1)) {prev_error = -7; return -7;} //chỉnh sửa lại thêm logic
          else if ( (Line[1]==1) && (Line[2]==1) && (Line[3]==1)) {prev_error = -5; return -5;}
          else if ( (Line[2]==1) && (Line[3]==1) && (Line[4]==1)) {prev_error = -3; return -3;}
          else if ( (Line[3]==1) && (Line[4]==1) && (Line[5]==1)) {prev_error = -1; return -1;}
          else if ( (Line[4]==1) && (Line[5]==1) && (Line[6]==1)) {prev_error = 1; return 1;}
          else if ( (Line[5]==1) && (Line[6]==1) && (Line[7]==1)) {prev_error = 3; return 3;}
          else if ( (Line[6]==1) && (Line[7]==1) && (Line[8]==1)) {prev_error = 5; return 5;}
          else if ( (Line[7]==1) && (Line[8]==1) && (Line[9]==1)) {prev_error = 7; return 7;}
          else return prev_error;
          break;
      }
    case 4: {
        if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1) {
          switch (CheckBarrie(-1)) {
            case 0: {
                prev_error = 0;
                return 0;
              }
            case -1: case 1:  {
                prev_error = -8;
                return -8;
              }
          }
        }
        else if (Line[9]==1 && Line[8]==1 && Line[7]==1 && Line[6]==1) {
          switch (CheckBarrie(1)) {
            case 0: {
                prev_error = 0;
                return 0;
              }
            case 1: case -1: {
                prev_error = 8;
                return 8;
              }
          }
        }
        else return prev_error;
        break;
      }
    case 5: {
             if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1) { prev_error = -9; return -9; }
        else if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1) { prev_error = -7; return -7; }
        else if (Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1) { prev_error = -5; return -5; }
        else if (Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1) { prev_error = 5; return 5; }
        else if (Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 7; return 7; }
        else if (Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = 9; return 9; }
        else return prev_error;
        break;
            }
    case 6: {
           if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1) { prev_error = -9; return -9; }
      else if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1) { prev_error = -7; return -7; }
      else if (Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1) { prev_error = 0; return 0; }
      else if (Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 7; return 7; }
      else if (Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = 9; return 9; }
      else return prev_error;
      break;
            }
    case 7: {
      prev_error = 0;
      return 0;
    }
    case 8: {
      prev_error = 0;
      return 0;
    }
    case 9: {
      prev_error = 0;
      return 0;
    }
    default: {
        /*int temp = CountLeft() - CountRight();
          if (temp < -1) {
          prev_error = 8;
          return 8;
          } else if (temp > 1) {
          prev_error = -8;
          return -8;
          } else*/
        return 0;
        break;
      }
  }
}
int CountLeft() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (Line[i]) count++;
  }
  return count;
}

int CountRight() {
  int count = 0;
  for (int i = 5; i < 10; i++) {
    if (Line[i]) count++;
  }
  return count;
}

int HighSignalCount() { //Count the high signal that speed up the GetError function
  int count = 0;
  for (int i = 0; i < 10; i++) {
    if (Line[i] == true) {
      count++;
    }
  }
  return count;
}

void CheckModeSwitch() { //Check if the robot is in the maze or on the line
  if (Mode == 0) {
    if (GetDistance(1) < 200) {
      double temp = GetDistance(0) + GetDistance(2);
      if (temp < 50) {
        Mode = 1;
        StopAllMotor();
        return;
      }
    }
  } else {
    GetSensorStatus();
    int temp = HighSignalCount();
    if (temp > 0 && temp < 10) {
      Mode = 0;
      StopAllMotor();
      return;
    }
  }
}
