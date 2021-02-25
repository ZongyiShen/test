package com.example.myapplication;

import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d("MainActivity","HelloWorld test");
        Log.i("MainActivity","MainActivity layout is complete");
        Log.e("MainActivity","HelloWorld");
        Log.w("MainActivity","HelloWorld");
    }
}