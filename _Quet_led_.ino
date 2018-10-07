int PIN_A = 2;
int PIN_B = 3;
int PIN_C = 4;
int PIN_D = 5;
int PIN_E = 6;
int PIN_F = 7;
int PIN_G = 8;
int POW_1 = 13;
int POW_2 = 12;
int i = 0, j = 0, n = 0;

int Arduino_Pins[7] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
int Segment_Pins[10][7] = {{0,1,1,1,1,1,1},
                           {0,0,0,0,1,1,0},
                           {1,0,1,1,0,1,1},
                           {1,0,0,1,1,1,1},
                           {1,1,0,0,1,1,0},
                           {1,1,0,1,1,0,1},
                           {1,1,1,1,1,0,1},
                           {0,0,0,0,1,1,1},
                           {1,1,1,1,1,1,1},
                           {1,1,0,1,1,1,1},
                          };

void setup()
{
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(POW_1, OUTPUT);
  pinMode(POW_2, OUTPUT);
}
void loop() {
  for(i=0;i<10;i++)
  {
    digitalWrite(POW_1,0);
    digitalWrite(POW_2,1);
    for(j = 0; j<7;j++)
    {
      digitalWrite(Arduino_Pins[j], Segment_Pins[n][j]);
    }
    delay(50);

    digitalWrite(POW_1,1);
    digitalWrite(POW_2,0);
    for(j = 0; j<7;j++)
    {
      digitalWrite(Arduino_Pins[j], Segment_Pins[i][j]);
    }
    delay(50);
    if(i==9)
    {
      n++;
      if(n>9)
      {
        n=0;
      }
    }
  }
}

