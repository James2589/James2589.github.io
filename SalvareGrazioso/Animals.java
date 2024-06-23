package application;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class Animals {
	 private final SimpleIntegerProperty id;
	    private final SimpleStringProperty name;
	    private final SimpleStringProperty breed;
	    private final SimpleStringProperty outcomeType;
	    private final SimpleStringProperty age;
	    private final SimpleStringProperty gender;
	    private final SimpleStringProperty city;
	    private final SimpleStringProperty state;

	    public Animals(Integer id, String name, String breed, String outcomeType, String age, String gender, String city, String state) {
	        this.id = new SimpleIntegerProperty(id);
	        this.name = new SimpleStringProperty(name);
	        this.breed = new SimpleStringProperty(breed);
	        this.outcomeType = new SimpleStringProperty(outcomeType);
	        this.age = new SimpleStringProperty(age);
	        this.gender = new SimpleStringProperty(gender);
	        this.city = new SimpleStringProperty(city);
	        this.state = new SimpleStringProperty(state);
	    }
	    
	    public Integer getId() {
	        return id.get();
	    }

	    public String getName() {
	        return name.get();
	    }

	    public String getBreed() {
	        return breed.get();
	    }

	    public String getOutcomeType() {
	        return outcomeType.get();
	    }
	    
	    public String getAge() {
	        return age.get();
	    }

	    public String getGender() {
	        return gender.get();
	    }

	    public String getCity() {
	        return city.get();
	    }
	    
	    public String getState() {
	        return state.get();
	    }

	    public void setName(String fname) {
	        name.set(fname);
	    }

	    public void setBreed(String dbreed) {
	        breed.set(dbreed);
	    }

	    public void setOutcomeType(String doutcomeType) {
	        outcomeType.set(doutcomeType);
	    }
	    
	    public void setAge(String dage) {
	        breed.set(dage);
	    }
	    
	    public void setGender(String dgender) {
	        breed.set(dgender);
	    }
	    
	    public void setCity(String dcity) {
	        breed.set(dcity);
	    }
	    
	    public void setState(String dstate) {
	        breed.set(dstate);
	    }
	}