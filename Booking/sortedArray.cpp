public static boolean isSorted(int[] a){
    boolean isSorted = true;
    boolean isAscending = a[1] > a[0];
    if(isAscending) {
        for (int i = 0; i < a.length-1; i++) {
            if(a[i] > a[i+1]) {
                isSorted = false;
                break;
            }           
        }
    } else {//descending
        for (int i = 0; i < a.length-1; i++) {
            if(a[i] < a[i+1]) {
                isSorted = false;
                break;
            }           
        }  
    }    
    return isSorted;
}
