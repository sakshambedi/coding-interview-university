"use strict"
const assert = require ("assert");


/**
  * Recursivly search for the searchElement and return Iindex of the searchElement in array   
  * @param array Sorted array 
  * @param searchElement Element you are trying to look for 
  * @param startIndex Starting index of the array
  * @param endIndex Ending index of the array
  * @returns Integer */
function binarySearchRecursive( array , searchElement ,startIndex , endIndex ) {
  if(startIndex > endIndex ) return -1;
  
  let midIndex = Math.floor((endIndex + startIndex) / 2 );
  
  if(array[midIndex] == searchElement) return midIndex;

  return (array[midIndex] < searchElement ) ? binarySearchRecursive(array , searchElement , midIndex + 1, endIndex) 
                                            : binarySearchRecursive(array , searchElement , startIndex , midIndex-1);
}



/**
  * Interatively search for the searchElement and return index of the searchElement in array   
  * @param array Sorted array 
  * @param searchElement Element you are trying to look for 
  * @returns Integer  */
function binarySearchIterative( array , searchElement ) {
  var startIndex =0;
  var endIndex = array.length - 1;

  while(startIndex <= endIndex ){
    let midIndex = Math.floor((startIndex + endIndex) / 2);  

    if(array[midIndex] == searchElement) return midIndex;

    if(array[midIndex] < searchElement) 
        startIndex = midIndex + 1;
    else 
        endIndex = midIndex-1; 
  }
  return -1
}

/**
 
*/
function main(){
  let array1= [1,2,3,4,5,6,8,12];
  console.log( binarySearchIterative(array1 , 8) == 6);
  console.log( binarySearchRecursive(array1 , 8 ,0 , array1.length - 1) == 6);
  
  array1 = [20 , 30 ,50 , 90 , 120, 324];
  console.log( binarySearchRecursive(array1 , 10 ,0 , array1.length - 1) == -1);
  console.log( binarySearchRecursive(array1 , 30 ,0 , array1.length - 1) == 1);

}

main();
