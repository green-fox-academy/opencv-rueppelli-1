#Developers docs.

[ReadDataBase](##readDataBase) [CreateRecord](##createRecord) 

##readDataBase

```int readDataBase(std::string databasePath)```

  - parameters: 
      - databasePath ( the database that you want to put data in )
  - return type:
      - int ( 1 if can't open database, 0 if successfully opened database )
  - purpose:
      - the function checks if the parameter database is opened
      
##createRecord

```int createRecord(std::string databasePath, std::string tableName, std::string path, double processingTime, int detectedCircles)```

  - parameters:
      - databasePath ( the database that you want to put data in )
      - tableName ( the table that you want to put data in )
      - path ( the path of the picture what you want put in the table )
      - processingTime ( the processing time of detecting the circles )
      - detectedCircles ( the number of the circles detected in the picture )
   - return type:
      - int ( 0 if the record is created succesfully, 1 if any type of error happened )
   - purpose:
      - with the help of this function, you can add new records to your own table - // path, processing time, detected circles //
      
      
