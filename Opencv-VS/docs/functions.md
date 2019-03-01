# Developers docs.

## database_handler.cpp

  [readDataBase](#readDataBase)
  
  [createRecord](#createRecord)
  
  [deleteRecord](#deleteRecord)
  
  [updateRecord](#updateRecord)
  
  [selectRecords](#selectRecords)

## detect_circles.cpp

  [detectCircles](#detectCircles)

## main.cpp

  [bluringImage](#bluringImage)

## sorting.cpp

  [selectionSort](#selectionSort)
  
  [insertionSort](#insertionSort)
  
  [quickSort](#quickSort)
  
  [mergeSort](#mergeSort)
  
  [shellSort](#shellSort)
  
  [heapSort](#heapSort)

### readDataBase

```int readDataBase(std::string databasePath)```

  - parameters: 
      - databasePath ( the database that you want to put data in )
  - return type:
      - int ( 1 if can't open database, 0 if successfully opened database )
  - purpose:
      - the function checks if the parameter database is opened
      
### createRecord

```int createRecord(std::string databasePath, std::string tableName, std::string path, double processingTime, int detectedCircles)```

  - parameters:
      - databasePath ( the database that you want to put data in )
      - tableName ( the table that you want to put data in )
      - path ( the path of the picture what you want put in the table )
      - processingTime ( the processing time of detecting the circles )
      - detectedCircles ( the number of the circles detected in the picture )
   - return type:
      - int ( 0 if the record is created succesfully, 1 if any type of error occured )
   - purpose:
      - with the help of this function you can add new records to your own table - // path, processing time, detected circles //
      
### deleteRecord

```int deleteRecord(std::string databasePath, std::string tableName, int id)```

  - parameters: 
      - databasePath ( the database you want to delete from )
      - tableName ( the table you want to delete from )
      - id ( the ID of the data which you want to delete )
  - return type:
      - int ( 0 if the record is deleted succesfully, 1 if any type of error occured )
  - purpose:
      - with the help of this function you can delete records from your own table
      
### updateRecord

```int updateRecord(std::string databasePath, std::string tableName, std::string userCmdAfterSet)```

  - parameters: 
      - databasePath ( the database you want update )
      - tableName ( the table you want update )
      - userCmdAfterSet ( the SQL code after 'SET' command )
  - return type:
      - int ( 0 if the record is modified succesfully, 1 if any type of error occured )
  - purpose:
      - with the help of this function you can modify values in your table
      
### selectRecords

```int selectRecords(std::string databasePath, std::string tableName, std::string chooseRecord)```

  - parameters: 
      - databasePath ( the database you want to select from )
      - tableName ( the table you want select from )
      - chooseRecord ( the record you want to choose from )
  - return type:
      - int ( 0 if the record is chosen successfully, 1 if any type of error occured )
  - purpose:
      - with the help of this function you can select records from the given table
      
      
### detectCircles

```int detectCircle(cv::Mat img)```

   - parameters:
      - img ( the picture you want to use )
   - return type:
      - int ( numbers of circles detected )
   - purpose:
      - this function detects the number of circles in the picture
      
### bluringImage

```void bluring_image()```

   - purpose:
      - this function can create trackbars
      
     
### selectionSort

```std::vector<int> selectionSort(std::vector<int> myVector, int &counter, int order)```

```int* selectionSort(int myArray[], int sizeOfArray, int &counter, int order)```

   - parameters: 
      - myVector/myArray ( the vector/array you want to sort )
      - sizeOfArray ( only if it's an array )
      - &counter ( counts the steps ) 
      - order ( if the value is 0 it prints out the numbers in descending order, if 1 it prints out the numbers in increasing order, ((default value = 1)) )
   - return type:
      - std::vector<int>/int* ( returns the sorted vector/array )
   - purpose:
      - the aim of this function is to sort the numbers of the vector/array in descending or increasing order
   
### insertionSort

```std::vector<int> insertion_sort(std::vector<int> vector, int size, int &counter, int command)```

```int *insertion_sort(int *array, int size, int &counter, int command)```

  - parameters: 
      - vector/array ( the vector/array you want to sort )
      - size ( size of the vector/array )
      - &counter ( counts the steps ) 
      - command ( if the value is 0 it prints out the numbers in descending order, if 1 it prints out the numbers in increasing order, ((default value = 1)) )
   - return type:
      - std::vector<int>/int* ( returns the sorted vector/array )
  - purpose:
      - the aim of this function is to sort the numbers of the vector/array in descending or increasing order

### quickSort

```std::vector<int> quickSort(std::vector<int> unsorted, int low, int high, int &counter, int order)```

```int* quickSort(int* array, int low, int high, int &counter, int order)```

   - parameters: 
      - unsorted/array ( the vector/array you want to sort )
      - low ( used for recursion - value is always = 0 )
      - high ( used for recursion - value is always 'size - 1' )
      - &counter ( counts the steps )
      - order ( if the value is 0 it prints out the numbers in descending order, if 1 it prints out the numbers in increasing order, ((default value = 1)) )
   - return type:
      - std::vector<int>/int* ( returns the sorted vector/array )
   - purpose:
       - the aim of this function is to sort the numbers of the vector/array in descending or increasing order
  
  ### mergeSort
  
  ```std::vector<int> mergeSort(std::vector<int> unsorted, int low, int high, int &counter, int order)```
  
  ```int* mergeSort(int *unsorted, int low, int high, int &counter, int order)```
  
   - parameters: 
      - unsorted ( the vector/array you want to sort )
      - low ( used for recursion - value is always = 0 )
      - high ( used for recursion - value is always 'size - 1' )
      - &counter ( counts the steps )
      - order ( if the value is 0 it prints out the numbers in descending order, if 1 it prints out the numbers in increasing order, ((default value = 1)) )
   - return type:
      - std::vector<int>/int* ( returns the sorted vector/array )
   - purpose:
       - the aim of this function is to sort the numbers of the vector/array in descending or increasing order
  
  ### shellSort
  
  ```int *shellSort(int *array, int size, int &counter, int command)```
  
  ```std::vector<int> shellSort(std::vector<int> &vector, int size, int &counter, int command)```
  
  - parameters: 
      - vector/array ( the vector/array you want to sort )
      - size ( size of the vector/array )
      - &counter ( counts the steps ) 
      - command ( if the value is 0 it prints out the numbers in descending order, if 1 it prints out the numbers in increasing order, ((default value = 1)) )
   - return type:
      - std::vector<int>/int* ( returns the sorted vector/array )
  - purpose:
      - the aim of this function is to sort the numbers of the vector/array in descending or increasing order
  
  ### heapSort
  
  ```int* heapSort(int unsorted[], int size, int &counter, int order)```
  
  ```std::vector<int> heapSort(std::vector<int> unsorted, int size, int &counter, int order)```

  - parameters: 
      - unsorted ( the vector/array you want to sort )
      - size ( size of the vector/array )
      - &counter ( counts the steps ) 
      - order ( if the value is 0 it prints out the numbers in descending order, if 1 it prints out the numbers in increasing order, ((default value = 1)) )
   - return type:
      - std::vector<int>/int* ( returns the sorted vector/array )
  - purpose:
      - the aim of this function is to sort the numbers of the vector/array in descending or increasing order
