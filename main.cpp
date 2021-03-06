#include<iostream>
using namespace std ;
#define N 9
int ** create( int n ){
    int ** t = new int * [n] ;
    for( int i = 0 ; i < n ; i ++ ) t[i] = new int[n] ;
    return t ;
}
bool FindUnassignedLocation( int ** grid , int &row , int &col ) ;
bool isSafe( int ** grid , int row , int col , int num ) ;
bool Solve( int ** grid ){
    int row , col ;
    if(!FindUnassignedLocation(grid,row,col)) return true ;

    for( int num = 1 ; num <= 9 ; num++ ){
        if( isSafe(grid,row,col,num) ){
            grid[row][col] = num ;
            if( Solve(grid) ) return true ;
            grid[row][col] = 0 ;
        }
    }
    return false ;

}
bool FindUnassignedLocation( int ** grid , int &row , int &col ){
    for( row = 0 ; row < N ; row++ ){
        for( col = 0 ; col < N ; col++ ){
            if( grid[row][col] == 0) return true ;
        }
    }
    return false ;
}
bool UsedInRow( int ** grid , int row , int num ){
    for( int i = 0 ; i < N ; i++ ){
        if( grid[row][i] == num ) return true ;
    }
    return false ;
}
bool UsedInCol( int ** grid , int col , int num ){
    for( int i = 0 ; i < N ; i++ ){
        if( grid[i][col] == num ) return true ;
    }
    return false ;
}
bool UsedInBox( int ** grid , int rowS , int colS , int num ){
    for( int i = 0 ; i < 3 ; i++ ){
        for( int j = 0 ; j < 3 ; j++ ){
            if( grid[i+rowS][j+colS] == num ) return true ;
        }
    }
    return false ;
}
bool isSafe( int ** grid , int row , int col , int num ){
    return ( !UsedInRow( grid , row , num ) && !UsedInCol( grid , col , num ) && !UsedInBox( grid , row-row%3 , col-col%3 , num ) && grid[row][col] == 0 );
}
void print( int ** grid ){
    cout << endl ;
    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < N ; j++ ){
            cout << grid[i][j] << " ";
        }
        cout << endl ;
    }
}
void take_input( int ** grid ){
    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < N ; j++ ){
            cin >> grid[i][j] ;
        }
    }
}
int main(){
    int ** grid = create(N) ;
    take_input(grid) ;
    Solve( grid ) ;
    print( grid ) ;
    return 0 ;
}
