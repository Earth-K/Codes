#include<cstdio>
#include<cstring>
int n;
char str[20000][51];
char temp[20000][51];
bool cmp(const char* s1, const char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 < len2){
        return true;
    }
    else if(len1 == len2){
        int i,j;
        i=j=0;
        while(s1[i] != NULL){
            if(s1[i] != s2[j])
                break;
            i++, j++;
        }
        if(i==len1) 
            return false;
        else
            return s1[i]<s2[j];
    }
    else{
        return false;
    }
}
void mergeSort(int s, int e){
    if(s>=e) return;
    int i,j,k;
    int mid = (s+e)>>1;
    i=s, j=mid+1, k=s;

    mergeSort(s,mid);
    mergeSort(mid+1,e);

    while(i<=mid && j<=e){
        if(cmp(str[i],str[j]))
            strcpy(temp[k++],str[i++]);
        else
            strcpy(temp[k++],str[j++]);
    }
    while(i<=mid)  strcpy(temp[k++],str[i++]);
    while(j<=e)  strcpy(temp[k++],str[j++]);
    for(int q=s; q<=e; q++)
        strcpy(str[q],temp[q]);
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%s",str[i]);
    
    mergeSort(0,n-1);
    
    char preStr[51];
    for(int i=0; i<n; i++){
        if(strcmp(preStr,str[i]) == 0)
            continue;
        printf("%s\n",str[i]);
        strcpy(preStr,str[i]);
    }

    return 0;
}