package com.example.myapplication04;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class LoginActivity extends AppCompatActivity {
    public static final int REQUEST_CODE_MAIN = 101;

    EditText usernameInput;
    EditText passwordInput;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        Button button = findViewById(R.id.button11);
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
}