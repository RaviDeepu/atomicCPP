1) Insert 2nd array values into hash map
2) Iterate through 1st array and square each value
3) Check for squared value in hash map and print match

If you replace unordered_map ( find() runs O(n) time as worst case) with your own hash map and assume no collisions, this solution runs in O(n) time complexity.


void CheckSquares(int *a1, int *a2, int len1, int len2){

  std::unordered_map<int, bool> ht;
  int temp;
  int i;
  
  // 1) Insert 2nd array values into hash map
  for(i = 0; i < len2; i++)
    ht[ a2[i] ] = 1;
  
  
  // 2) Iterate through 1st array, square the values and print matches
  for(i = 0; i < len1; i++) {
    temp = pow(a1[i], 2);
    if( ht.find( temp ) != ht.end() )
      std::cout << temp << std::endl;
  }
  

}
