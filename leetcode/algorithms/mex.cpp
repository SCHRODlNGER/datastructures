int mex(vector<int> &a){

    int n = a.size();

    for(int i=0;i<n;i++){
        int correctPos = a[i] - 1;

        while ((1 <= a[i] && n>=a[i] ) && a[i] != a[correctPos]){
            swap(a[i], a[correctPos]);
            correctPos = a[i] - 1;
        }

    }


    int ans = n + 1;
    for(int i=0;i<n;i++){
        if(a[i] != i + 1)
            ans = i+1;
    }

    return ans;
}