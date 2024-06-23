from pymongo import MongoClient
from bson.objectid import ObjectId
from pprint import pprint

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self, userName, userPass, userHost, userPort, userDb, userCol):
        # Initializing the MongoClient. This helps to 
        # access the MongoDB databases and collections.
        # This is hard-wired to use the aac database, the 
        # animals collection, and the aac user.
        # Definitions of the connection string variables are
        # unique to the individual Apporto environment.
        #
        # You must edit the connection variables below to reflect
        # your own instance of MongoDB!
        #
        # Connection Variables
        #
        USER = userName
        PASS = userPass
        HOST = userHost
        PORT = userPort
        DB = userDb
        COL = userCol
        #
        # Initialize Connection
        #
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
        self.database = self.client['%s' % (DB)]
        self.collection = self.database['%s' % (COL)]

# Complete this create method to implement the C in CRUD.
    def create(self, data):
        if data is not None:
            docCreator = self.database.animals.insert_one(data)  # data should be dictionary
            if docCreator.inserted_id:
                pprint(docCreator)
                return True
            else: 
                return False
        else:
            raise Exception("Nothing to save, because data parameter is empty")

# Create method to implement the R in CRUD.
    def read(self, userSearch):
        #searchs animals collection 
            data = list(self.database.animals.find(userSearch))
            #if data is not None:
                #pprint(data)
            #else: 
                #pprint({})
            return data

#update method to implement the U in CRUD
    def update(self, userSearch, userUpdate):
        #userSearch specifies document to update, userUpdate provides new data
        if userSearch is not None:
            result = self.database.animals.update_many(userSearch, {"$set": userUpdate})
            pprint(result.modified_count)
        else:
            pprint({})
            
#delete method to implement the D in CRUD
    def delete(self, userDelete):
        #deletes instances that match userDelete
        if userDelete is not None:
            removed = self.database.animals.delete_many(userDelete)
            pprint(removed.deleted_count)
        else:
            pprint({})
            

        