struct BodyTransmitData
{
    int16_t TopLeftXJoystick = 512;
    int16_t TopLeftYJoystick = 512;
    int16_t TopRightXJoystick = 512;
    int16_t TopRightYJoystick = 512;

    int16_t BottomLeftXJoystick = 512;
    int16_t BottomRightXJoystick = 512;
    // but1 (stick 1) from Joe is selecting between dome servo and dome spin
    // Naigon - this now cycles through the combined drive mode and dome mode.
    // int but1 = 1; //left select
    // but2 from Joe is audio
    // Naigon - button 2 press plays a happy/neutral sound. Holding plays a longer/sader sound
    // int but2 = 1; //left button 1
    // but3 from Joe is audio
    // Naigon - button 3 press starts music, and cycles tracks. Holding stops music.
    // int but3 = 1; //left button 2
    // but4 from Joe is to trigger Body/dome lighting changes
    // Naigon - Button 4 TBD
    // int but4 = 1; //left button 3
    // but5 (stick 2) toggles fwd/rev
    // int but5 = 0; //right select (fwd/rev)
    // but6 from Joe is for switching between drive speeds
    // Naigon - Button 6 is now TBD.
    // int but6 = 1; //right button 1
    // but7 from Joe is for body calibration only currently when holding
    // int but7 = 1; //right button 2
    // but8 is for select only
    // int but8 = 1; //right button 3 (right select)
    // int motorEnable = 1;
};