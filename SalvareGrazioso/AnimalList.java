package application;

import com.mongodb.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoCursor;
import com.mongodb.client.MongoDatabase;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.stage.Stage;
import org.bson.Document;


import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

import static com.mongodb.client.model.Filters.eq;


public class AnimalList implements Initializable{
    private final static String HOST = "localhost";
    private final static int PORT = 27017;
    private String animalName;
    private String animalBreed;
    private String animalOutcomeType;
    private String animalAge;
    private String animalGender;
    private String animalCity;
    private String animalState;
    private int pos;

    @FXML
    private Label status;
    @FXML
    private TableView<Animals> table;
    @FXML
    private TableColumn<Animals, Integer> id;
    @FXML
    private TableColumn<Animals, String> name;
    @FXML
    private TableColumn<Animals, String> breed;
    @FXML
    private TableColumn<Animals, String> outcomeType;
    @FXML
    private TableColumn<Animals, String> age;
    @FXML
    private TableColumn<Animals, String> gender;
    @FXML
    private TableColumn<Animals, String> city;
    @FXML
    private TableColumn<Animals, String> state;
    @FXML
    private Button addAnimal;

    //create a primary stage object
    Stage primaryStage = new Stage();

    //create an observable list to hold the Animals object in the Animals class
    public ObservableList<Animals> list;

    public List<Animals> animals = new ArrayList<Animals>();


    //create a mongodb connection
    MongoClient mongoClient = new MongoClient(HOST, PORT);

    //create SalvareGrazioso database
    MongoDatabase mongoDatabase = mongoClient.getDatabase("SalvareGrazioso");

    //create animals collection
    MongoCollection<Document> coll = mongoDatabase.getCollection("animals");
    
    //create cursor iterator
    MongoCursor<Document> cursor = coll.find().iterator();

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        table.setEditable(true);

        try{
            for(int i = 0; i < coll.countDocuments(); i++){
                pos = i +1;

                Document doc = cursor.next();
                animalName = doc.getString("name");
                animalBreed = doc.getString("breed");
                animalOutcomeType = doc.getString("outcomeType");
                animalAge = doc.getString("age");
                animalGender = doc.getString("gender");
                animalCity = doc.getString("city");
                animalState = doc.getString("state");

                animals.add(new Animals(pos, animalName, animalBreed, animalOutcomeType, animalAge, animalGender, animalCity, animalState ));
            }
            list = FXCollections.observableArrayList(animals);


        }
        finally {
            //close the connection
            cursor.close();
        }

        //call the setTable method
        setTable();
    }



    public void addAnimal() throws Exception{
        //get the current window
        Stage stage = (Stage)addAnimal.getScene().getWindow();

        //close the current window
        stage.close();

        //load the main class window
        Main mainClass = new Main();

        mainClass.start(primaryStage);
    }

    public void editAnimalList() {
        Animals selectedItem = table.getSelectionModel().getSelectedItem();
        if (selectedItem == null){
            //display an error message if no row was selected
            status.setText("Please select a row and perform this action again");
        }
        else{
            animalName = selectedItem.getName();
            animalBreed = selectedItem.getBreed();
            animalOutcomeType = selectedItem.getOutcomeType();
            animalAge = selectedItem.getAge();
            animalGender = selectedItem.getGender();
            animalCity = selectedItem.getCity();
            animalState = selectedItem.getState();

            //using name as search criteria to update document
            coll.updateOne(eq("name", animalName), new Document("$set",
                    new Document("name",animalName )
                            .append("breed", animalBreed)
                            .append("outcomeType", animalOutcomeType)
                            .append("age", animalAge)
                            .append("gender", animalGender)
                            .append("city", animalCity)
                            .append("state", animalState)));
            

            //call the rePopulateTable method
            rePopulateTable();

            //call the setTable method
            setTable();

            //hide the error message
            status.setText("");
        }

    }


    public void deleteAnimal(){
        //get the selected row
        Animals selectedItem = table.getSelectionModel().getSelectedItem();
        if (selectedItem == null){
            //display an error message
            status.setText("Please select a row and perform this action again");
        }
        else{
            //get the value of the selected name column
            String name = selectedItem.getName();

            //using the email as the primary key to find each document to delete from the database
            coll.deleteOne(eq("name", name));

            //call the rePopulateTable method
            rePopulateTable();

            //call the setTable method
            setTable();

            //hide the error message
            status.setText("");
        }
    }

    public void setTable(){
        //this makes the table editable
        table.setEditable(true);

        //make name column editable with a textfield
        name.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setname method
        name.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {

                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setName(event.getNewValue());

            }
        });

        //make breed column editable with a textfield
        breed.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setbreed method
        breed.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {
                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setBreed(event.getNewValue());
            }
        });

        //make outcome type column editable with a textfield
        outcomeType.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setOutcomeType method
        outcomeType.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {
                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setOutcomeType(event.getNewValue());
            }
        });
        
        //make age column editable with a textfield
        age.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setage method
        age.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {
                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setAge(event.getNewValue());
            }
        });
        
        //make gender column editable with a textfield
        gender.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setGender method
        gender.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {
                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setGender(event.getNewValue());
            }
        });
        
        //make city column editable with a textfield
        city.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setCity method
        city.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {
                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setCity(event.getNewValue());
            }
        });
        
        //make state column editable with a textfield
        state.setCellFactory(TextFieldTableCell.forTableColumn());

        //gets the new value and calls the setState method
        state.setOnEditCommit(new EventHandler<TableColumn.CellEditEvent<Animals, String>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Animals, String> event) {
                ((Animals)event.getTableView().getItems().get(event.getTablePosition().getRow()))
                        .setState(event.getNewValue());
            }
        });

        //set the values of each columns to display on the table
        id.setCellValueFactory(new PropertyValueFactory<Animals, Integer>("id"));
        name.setCellValueFactory( new PropertyValueFactory<Animals, String>("name"));
        breed.setCellValueFactory( new PropertyValueFactory<Animals, String>("breed"));
        outcomeType.setCellValueFactory( new PropertyValueFactory<Animals, String>("outcomeType"));
        age.setCellValueFactory( new PropertyValueFactory<Animals, String>("age"));
        gender.setCellValueFactory( new PropertyValueFactory<Animals, String>("gender"));
        city.setCellValueFactory( new PropertyValueFactory<Animals, String>("city"));
        state.setCellValueFactory( new PropertyValueFactory<Animals, String>("state"));
        table.setItems(list);
    }

    private void rePopulateTable(){
        //creates a cursor iterator
        MongoCursor<Document> cursor = coll.find().iterator();

        //clears the animal list to clear the table
        animals.clear();
        try{
            //loop through the database and then populate the list
            for(int i = 0; i < coll.countDocuments(); i++){
                pos = i +1;

                Document doc = cursor.next();
                animalName = doc.getString("name");
                animalBreed = doc.getString("breed");
                animalOutcomeType = doc.getString("outcomeType");
                animalAge = doc.getString("age");
                animalGender = doc.getString("gender");
                animalCity = doc.getString("city");
                animalState = doc.getString("state");

                animals.add(new Animals(pos, animalName, animalBreed, animalOutcomeType, animalAge, animalGender, animalCity, animalState ));
            }
            list = FXCollections.observableArrayList(animals);


        }
        finally {
            //close the connection
            cursor.close();
        }
    }
}