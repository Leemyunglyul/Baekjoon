#include <stdio.h>

int main() {
    int testn, n, i, x, y, anw, tmp;
    char a, b;
    
    scanf("%d", &testn);
    
    while (testn--) {
        scanf("%d", &n);
        anw = 2;
        tmp = 0;
        
        while (n--) {
            scanf(" %c %d %c %d", &a, &x, &b, &y);
            
            for (i = 0; i <= 6; i++) {
                if (!((1 << i) & anw)) continue;
                
                if (a == '+') 
                    tmp |= (1 << ((i + x) % 7));
                else 
                    tmp |= (1 << ((i * x) % 7));
                
                if (b == '+') 
                    tmp |= (1 << ((i + y) % 7));
                else 
                    tmp |= (1 << ((i * y) % 7));
            }
            
            anw = tmp;
            tmp = 0;
        }
        
        if (anw & 1) 
            printf("LUCKY\n");
        else 
            printf("UNLUCKY\n");
    }

    return 0;
}
