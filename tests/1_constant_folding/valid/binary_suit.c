// Exit code: 0

int cte0 = 1 + 2;
int cte1 = 5 - 2;
int cte2 = 5 * 2;
int cte3 = 50 / 5;
int cte4 = 5 % 2;
int cte5 = 5 << 2;
int cte6 = 48 >> 3;
int cte7 = 5 > 2;
int cte8 = 1 >= 2;
int cte9 = 5 < 2;
int cte10 = 2 <= 2;
int cte11 = 5 == 2;
int cte12 = 5 != 2;
int cte13 = 54 & 21;
int cte14 = 5 ^ 2;
int cte15 = 5 | 2;
int cte16 = 5 && 2;
int cte17 = 0 || 2;
int cte18 = -10;
int cte19 = !0;
int cte20 = ~458;

int main() {
    if(cte1 != 3)       return 1; 
    if(cte2 != 10)      return 2; 
    if(cte3 != 10)      return 3; 
    if(cte4 != 1)       return 4; 
    if(cte5 != 20)      return 5; 
    if(cte6 != 6)       return 6; 
    if(cte7 != 1)       return 7; 
    if(cte8 != 0)       return 8; 
    if(cte9 != 0)       return 9; 
    if(cte10 != 1)      return 10; 
    if(cte11 != 0)      return 11; 
    if(cte12 != 1)      return 12; 
    if(cte13 != 20)     return 13; 
    if(cte14 != 7)      return 14; 
    if(cte15 != 7)      return 15; 
    if(cte16 != 1)      return 16; 
    if(cte17 != 1)      return 17; 
    if(cte18 != -10)    return 18; 
    if(cte19 != 1)      return 19; 
    if(cte20 != -459)   return 20; 
    if(cte0 != 3)       return 21; 

    return 0;
}