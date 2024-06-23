package application;

import com.mongodb.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import org.bson.Document;

import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable{
    private final static String HOST = "localhost";
    private final static int PORT = 27017;
    @FXML
    private TextField name;
    @FXML
    private TextField breed;
    @FXML
    private Label status;
    @FXML
    private TextField outcomeType;
    @FXML
    private TextField age;
    @FXML
    public ComboBox<String> gender;
    @FXML
    private TextField city;
    @FXML
    private TextField state;
    @FXML
    private Button animal;

    //create an observable list to hold the content of the combobox
    ObservableList<String> list  = FXCollections.observableArrayList("Male", "Female");

    //create a primary stage object
    Stage primaryStage = new Stage();

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        //set the items of the combobox
        gender.setItems(list);
    }

    public void getFieldValues(ActionEvent event){
        try{
            //create a connection to mongodb server
            MongoClient mongoClient = new MongoClient(HOST, PORT);

            //create a database name
            MongoDatabase mongoDatabase = mongoClient.getDatabase("SalvareGrazioso");

            //create a collection
            MongoCollection<Document> coll = mongoDatabase.getCollection("animals");

            //get the values of the fields
            Document doc = new Document("name", name.getText())
            		.append("name", name.getText())
                    .append("breed", breed.getText())
                    .append("outcomeType", outcomeType.getText())
                    .append("age", age.getText())
                    .append("gender", gender.getValue())
                    .append("city", city.getText())
                    .append("state", state.getText());

            //save the document
            coll.insertOne(doc);

            //display a success message
            status.setText("Save Successfull.");

            //set the fields to null or empty
            name.setText("");
            breed.setText("");
            outcomeType.setText("");
            age.setText("");
            gender.setValue(null);
            city.setText("");
            state.setText("");
        }
        catch (Exception e){
            System.out.println(e.getClass().getName() + ": " + e.getMessage());
            //display the error message
            status.setText("Failed to save");
        }
    }

    public void goToAnimalList() throws Exception{
        //get the current window
        Stage stage = (Stage)animal.getScene().getWindow();

        //close the current window
        stage.close();

        //load the animal list window
        Parent root = FXMLLoader.load(getClass().getResource("AnimalList.fxml"));
        primaryStage.setTitle("Animal List");
        primaryStage.setScene(new Scene(root, 1000, 500));
        primaryStage.show();

    }


}