int search( int key,int r[], int n ) 
{ 
int i,j; 
int tempr;
for ( i=0; i<n-1 && r[i] != key; i++ );
if ( key == r[i] ) 
{ if ( i>0 ) {
tempr = r[i]; 
for (j=0, j<i; j++) r[j+1]=r[j];
r[0]=tempr; 
}; 
return( i ); 
} else return( -1 );

int search( int key,int r[], int n ) 
{ 
int i; 
int tempr;
for ( i=0; i<n-1 && r[i] != key; i++ );
if ( key == r[i] ) 
{ if ( i>0 ) {
/*** Transpose with predecessor ***/ 
tempr = r[i]; 
r[i] = r[i-1];
r[--i] = tempr; 
}; 
return( i ); 
} else return( -1 ); 