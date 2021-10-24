package com.example.proposal;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.example.proposal.MainActivity;
import com.example.proposal.R;

public class LoginActivity extends AppCompatActivity {
    public static final int REQUEST_CODE_MAIN = 101;

    EditText usernameInput;
    EditText passwordInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        Button button = findViewById(R.id.button00);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //String username = usernameInput.getText().toString();
                //String password = passwordInput.getText().toString();

                Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                //intent.putExtra("username", username);
                //intent.putExtra("password", password);

                startActivityForResult(intent, REQUEST_CODE_MAIN);
            }
        });
    }

    /*public void onButton31Clicked(View v) {
        Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.chosun.ac.kr/"));
        startActivity(myIntent);
    }

    public void onButton41Clicked(View v) {
        Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.chosun.ac.kr/user/indexMain.do?siteId=ce"));
        startActivity(myIntent);
    }*/
}