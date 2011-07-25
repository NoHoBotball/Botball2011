//Add to Ben's program

/* 
                ,)(8)).
              (()))())()).
             (()"````"::= )
             )| _    _ ::= )
            (()(o)/ (o) ?(/)
             )(::c ::.( :(/)
            (( \ .__. ;,/(/)
              ) `.___,'/ (/)
                 |    | (/)
               _.'    ,\(/)__
           _.-"   ` u    (/) ".
         ,"               ^    \
        /                      |
        |           .      `.  |
        |   /,'   _  `.'   _ `.|
        |   ||   (o)  |   (o) ||
        |   |\        ;       /)
        (   \ `.,___,' `.,__,'/
         \   \ |           | /
          \   `;           |/
           `. /            |
      cjr    Y             |
      + cj  /          (   |
           /               ;
          /               /
         ;       ` .    ,'(
         |          \##'   \
         :           Y      \
          \           \      \
           \           \      \
            \           \      \ 
*/







































//SBNav2..I think :D :P :) XD :O <3

drivemm(75, 2); //Drive to middle, I think
TurnLeft(); 
while(digital(15) == 0)
{
	drive(250);
}
TurnRight();
while(get_create_rbump(0.1) == 0)
{
	drive(-250);
}
drivemm(150, 1);