#define FL_1 2
#define FL_2 3

#define FR_1 4
#define FR_2 5

#define MR_1 10
#define MR_2 11

#define ML_1 12
#define ML_2 13

#define BR_1 6
#define BR_2 7

#define BL_1 8
#define BL_2 9

// A0 FWD & BWD
// A1 LEFT and RIGHT

uint8_t throttle = 0;
uint8_t turn = 0;

void init_pins();
void read_inputs();
void set_direction();

void move_forward();
void move_back();
void turn_left();
void turn_right();
void stop();

void setup()
{

  init_pins();
}

void loop()
{
  read_inputs();
  set_direction();
}

void init_pins()
{

  pinMode(FL_1, OUTPUT);
  pinMode(FL_2, OUTPUT);

  pinMode(FR_1, OUTPUT);
  pinMode(FR_2, OUTPUT);

  pinMode(MR_1, OUTPUT);
  pinMode(MR_2, OUTPUT);

  pinMode(ML_1, OUTPUT);
  pinMode(ML_2, OUTPUT);

  pinMode(BR_1, OUTPUT);
  pinMode(BR_2, OUTPUT);

  pinMode(BL_1, OUTPUT);
  pinMode(BL_2, OUTPUT);
}

void read_inputs()
{
  throttle = analogRead(A0) / 4;
  turn = analogRead(A1) / 4;
}

void set_direction()
{
  if (throttle > 180)
  {
    move_forward();
    return;
  }
  else if (throttle < 80)
  {
    move_back();
  }
  else if (turn > 180)
  {
    turn_right();
  }
  else if (turn < 80)
  {
    turn_left();
  }
  else
    stop();
}

void move_forward()
{
  digitalWrite(FL_1, HIGH);
  digitalWrite(FL_2, LOW);

  digitalWrite(FR_1, HIGH);
  digitalWrite(FR_2, LOW);

  digitalWrite(BL_1, LOW);
  digitalWrite(BL_2, HIGH);

  digitalWrite(BR_1, LOW);
  digitalWrite(BR_2, HIGH);
}
void move_back()
{
  digitalWrite(FL_1, LOW);
  digitalWrite(FL_2, HIGH);

  digitalWrite(FR_1, LOW);
  digitalWrite(FR_2, HIGH);

  digitalWrite(BL_1, LOW);
  digitalWrite(BL_2, HIGH);

  digitalWrite(BR_1, LOW);
  digitalWrite(BR_2, HIGH);
}

void turn_left()
{
  digitalWrite(FL_1, LOW);
  digitalWrite(FL_2, HIGH);

  digitalWrite(FR_1, HIGH);
  digitalWrite(FR_2, LOW);

  digitalWrite(BL_1, LOW);
  digitalWrite(BL_2, HIGH);

  digitalWrite(BR_1, HIGH);
  digitalWrite(BR_2, LOW);
}
void turn_right()
{
  digitalWrite(FL_1, HIGH);
  digitalWrite(FL_2, LOW);

  digitalWrite(FR_1, LOW);
  digitalWrite(FR_2, HIGH);

  digitalWrite(BL_1, HIGH);
  digitalWrite(BL_2, LOW);

  digitalWrite(BR_1, LOW);
  digitalWrite(BR_2, HIGH);
}

void stop()
{
  digitalWrite(FL_1, HIGH);
  digitalWrite(FL_2, HIGH);

  digitalWrite(FR_1, HIGH);
  digitalWrite(FR_2, HIGH);

  digitalWrite(BL_1, HIGH);
  digitalWrite(BL_2, HIGH);

  digitalWrite(BR_1, HIGH);
  digitalWrite(BR_2, HIGH);
}