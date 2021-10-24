package com.example.termproject;

public class effects {
    String Outline;
    String Body;
    int imgID;

    public effects() {}

    public effects(String Outline, String Body, int imgID) {
        this.Outline = Outline;
        this.Body = Body;
        setImgID(imgID);
    }

    public String getOutline() {
        return Outline;
    }

    public void setOutline(String Outline) {
        this.Outline = Outline;
    }

    public String getBody() {
        return Body;
    }

    public void setBody(String Body) {
        this.Body = Body;
    }

    public  int getImgID() { return imgID; }

    public void setImgID(int imgID) {this.imgID = imgID; }
}
