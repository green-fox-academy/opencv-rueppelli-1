#Developers docs.

[ReadDataBase](#readDataBase) [CreateRecord](##createRecord)  [deleteRecord](##deleteRecord)

###readDataBase

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
      - int ( 0 if the record is created succesfully, 1 if any type of error occured )
   - purpose:
      - with the help of this function you can add new records to your own table - // path, processing time, detected circles //
      
#deleteRecord

```int deleteRecord(std::string databasePath, std::string tableName, int id)```

  - parameters: 
      - databasePath ( the database you want to delete from )
      - tableName ( the table you want to delete from )
      - id ( the ID of the data which you want to delete )
  - return type:
      - int ( 0 if the record is deleted succesfully, 1 if any type of error occured )
  - purpose:
      - with the help of this function you can delete records from your own table
      
#updateRecord

```int updateRecord(std::string databasePath, std::string tableName, std::string userCmdAfterSet)```

  - parameters: 
      - databasePath ( the database you want update )
      - tableName ( the table you want update )
      - userCmdAfterSet ( the SQL code after 'SET' command )
  - return type:
      - int ( 0 if the record is modified succesfully, 1 if any type of error occured )
  - purpose:
      - with the help of this function you can modify values in your table
      
#selectRecords

```int selectRecords(std::string databasePath, std::string tableName, std::string chooseRecord)```

   - parameters: 
      - databasePath ( the database you want to select from )
      - tableName ( the table you want select from )
      - chooseRecord ( the record you want to choose from )
  - return type:
      - int ( 0 if the record is chosen successfully, 1 if any type of error occured )
  - purpose:
      - with the help of this function you can select records from the given table
