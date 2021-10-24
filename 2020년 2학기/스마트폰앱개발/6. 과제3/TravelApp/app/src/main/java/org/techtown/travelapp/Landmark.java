package org.techtown.travelapp;

public class Landmark {
    String Location;
    String Address;
    int imgID;

    public Landmark() {}
    public Landmark(String Location, String Address, int imgID) {
        this.Location = Location;
        this.Address = Address;
        setImgID(imgID);
        //this.imgID = imgID;
    }

    public String getLocation() {
        return Location;
    }

    public void setLocation(String Location) {
        this.Location = Location;
    }

    public String getAddress() {
        return Address;
    }

    public void setAddress(String Address) {
        this.Address = Address;
    }

    public  int getImgID() { return imgID; }

    public void setImgID(int imgID) {this.imgID = imgID; }
}
