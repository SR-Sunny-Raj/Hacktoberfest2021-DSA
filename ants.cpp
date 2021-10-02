#include <bits/stdc++.h>

using namespace std ;

// 1: U, 2:D, 3:L, 4:R, 5:Anteater

bool finish(bool *x, int R, int C) {
    for (int i=0; i<R; ++i)
        for (int j = 0; j < C; ++j)
            for (int k = 0; k < 4; ++k)
                if (*(x + 5*(i*C+j) + k))
                    return false ;
    return true ;
}

int main(){
    int T ;
    cin >> T ;
    char temp ;
    for(int i=0; i<T; ++i){
        int R, C ;
        cin >> R >> C ;
        int anteaters = 0 ;
        bool arr[R][C][5];
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j) {
                cin >> temp ;
                switch (temp){
                    case 'U':
                        arr[i][j][0]=1 ;
                        break;
                    case 'D':
                        arr[i][j][1]=1 ;
                        break ;
                    case 'L':
                        arr[i][j][2]=1 ;
                        break ;
                    case 'R':
                        arr[i][j][3]=1 ;
                        break;
                    case '#':
                        arr[i][j][4]=1 ;
                        anteaters++ ;
                }
            }
        while(~finish(arr[0][0], R, C)){
            // Transform the bool arrar
            for (int i=0; i<R; ++i)
                for (int j = 0; j < C; ++j)
                    for (int k = 0; k < 5; ++k) {
                        if (arr[i][j][k]) {
                            switch (k) {
                                case 0:
                                    break;
                                case 1:
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    break;
                                case 4:
                                    1;
                            }
                            arr[i][j][k] = 0 ;
                        }
                    }
        }
    }
};