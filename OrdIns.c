/*ORDENAMIENTO POR INSERSION 
JOSÉ ANTONIO VÁZQUEZ PORTUGUEZ 2020630477
ADA 3CDM1 PROFESORA CECILIA ALBORTANTE */


void OrdIns(int *array, int N){
    int i=0;
    int x=0;
    for(int j=0; j<N; j++){  
        i=j-1;
        x=array[j];
        while((x<array[i])&&(i>=0)){
            array[i+1]=array[i];
            i=i-1;
        }
        array[i+1]=x;
    }
}