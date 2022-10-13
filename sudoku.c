#include<stdio.h>

void lire(int *t,int N,int M){
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            printf("donner l'element d'indice %d,%d : ",i,j);
            scanf("%d",t+i*M+j);
        };
    }
}

void affichage(int *t,int N,int M){
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){printf("+---");}
        printf("+\n");
        for (j=0;j<M;j++){
            printf("| %d ",*(t+i*M+j));
        };
        printf("|\n");
    };
    for (j=0;j<M;j++){printf("+---");}
    printf("+\n");
}

int listediff(int *t){
    int r=1,i,j,N=4;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            if (i!=j && *(t+i)==*(t+j)){
                r=0;
                break;
            };
        };
    };
    return r;
}
int matricevalid(int *t){
    int L0[4]={*t,*(t+1),*(t+2),*(t+3)},L1[4]={*(t+4),*(t+5),*(t+6),*(t+7)},L2[4]={*(t+8),*(t+9),*(t+10),*(t+11)},L3[4]={*(t+12),*(t+13),*(t+14),*(t+15)};
    int C0[4]={*t,*(t+4),*(t+8),*(t+12)},C1[4]={*(t+1),*(t+5),*(t+9),*(t+13)},C2[4]={*(t+2),*(t+6),*(t+10),*(t+14)},C3[4]={*(t+3),*(t+7),*(t+11),*(t+15)};
    int S0[4]={*t,*(t+1),*(t+4),*(t+5)},S1[4]={*(t+2),*(t+3),*(t+6),*(t+7)},S2[4]={*(t+8),*(t+9),*(t+12),*(t+13)},S3[4]={*(t+10),*(t+11),*(t+14),*(t+15)};//petit carrés
    int rc=listediff(C0)*listediff(C1)*listediff(C2)*listediff(C3);
    int rl=listediff(L0)*listediff(L1)*listediff(L2)*listediff(L3);
    int rs=listediff(S0)*listediff(S1)*listediff(S2)*listediff(S3);
    int r=rc*rl*rs;
    return r;
}

int interslistes(int *empl,int *tabgrand,int *tabbase){//empl et tabgrand est une matrice par contre tabbase est une liste de taille 4
    int i,j,k=0,l,u;
    for (i=0;i<24;i++){
        u=1;
        for (j=0;j<4;j++){
            if (*(tabbase+j)!=0 && *(tabgrand+i*4+j)!=*(tabbase+j)){
                u=0;
                break;
            };
        };
        if (u==1){
            for (j=0;j<4;j++){
                *(empl+k*4+j)=*(tabgrand+i*4+j);
            };
            k++;
        };
    };
    return k;
}

int main(){
    int T[24][4],i,k,l,j,m=0,su[4][4],T0[24][4],T1[24][4],T2[24][4],T3[24][4];
    for (i=1;i<=4;i++){
        for (j=1;j<=4;j++){
            if (j!=i){
                for (k=1;k<=4;k++){
                    if (k!=i && k!=j){
                        for (l=1;l<=4;l++){
                            if (l!=i && l!=j && l!=k){
                                T[m][0]=i;
                                T[m][1]=j;
                                T[m][2]=k;
                                T[m][3]=l;
                                m++;
                            }
                        };
                    };
                };
            };
        };
    };
    lire(&su[0][0],4,4);
    int *t;
    t=&su[0][0];
    int su0[4]={*t,*(t+1),*(t+2),*(t+3)},su1[4]={*(t+4),*(t+5),*(t+6),*(t+7)},su2[4]={*(t+8),*(t+9),*(t+10),*(t+11)},su3[4]={*(t+12),*(t+13),*(t+14),*(t+15)};
    int k0=interslistes(&T0[0][0],&T[0][0],&su0[0]);
    int k1=interslistes(&T1[0][0],&T[0][0],&su1[0]);
    int k2=interslistes(&T2[0][0],&T[0][0],&su2[0]);
    int k3=interslistes(&T3[0][0],&T[0][0],&su3[0]);
    int D[4][4];
    int trouvee=0;
    for (i=0;i<k0;i++){
        if (trouvee==1){break;}
        else{
            for (j=0;j<k1;j++){
                if (trouvee==1){break;}
                else{
                    for (k=0;k<k2;k++){
                        if (trouvee==1){break;}
                        else{
                            for (l=0;l<k3;l++){
                                D[0][0]=T0[i][0];
                                D[0][1]=T0[i][1];
                                D[0][2]=T0[i][2];
                                D[0][3]=T0[i][3];
                                D[1][0]=T1[j][0];
                                D[1][1]=T1[j][1];
                                D[1][2]=T1[j][2];
                                D[1][3]=T1[j][3];
                                D[2][0]=T2[k][0];
                                D[2][1]=T2[k][1];
                                D[2][2]=T2[k][2];
                                D[2][3]=T2[k][3];
                                D[3][0]=T3[l][0];
                                D[3][1]=T3[l][1];
                                D[3][2]=T3[l][2];
                                D[3][3]=T3[l][3];
                                if (matricevalid(&D[0][0])==1){
                                    affichage(&D[0][0],4,4);
                                    trouvee=1;
                                };
                            };
                        };
                    };
                };
            };
        };
    };
    return 0;
}