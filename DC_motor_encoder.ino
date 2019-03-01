#define PWM 6
#define INB 4
#define INA 3
#define EN 2

#define ENCODER_DT  8
#define ENCODER_CLK 7

unsigned long counter;
bool dt;
bool clk;
bool prev_clk;

void setup() 
{
    counter = 0;    
    pinMode(PWM, OUTPUT);
    pinMode(INB, OUTPUT);
    pinMode(INA, OUTPUT);
    pinMode(EN, OUTPUT);
}

void loop() 
{
    int dt = digitalRead(ENCODER_DT);
    int clk = digitalRead(ENCODER_CLK);

    // (обработка данных при спаде напряжения на clk)
    // Если уровень сигнала clk низкий
    // и в прошлый раз он был высокий
    if (!clk && prev_clk)
    {
        // Сигнал dt высокий, крутимся по часовой стрелке
        if (dt)
        {
            counter++;
        }
        else    // А тут сигнал низкий, значит против часовой
        {
            counter--;
        }
    }


    prev_clk = clk;
}
