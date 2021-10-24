package com.example.termproject;

import android.media.Image;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link smoking_fragment3#newInstance} factory method to
 * create an instance of this fragment.
 */
public class smoking_fragment3 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public smoking_fragment3() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment smoking_fragment3.
     */
    // TODO: Rename and change types and number of parameters
    public static smoking_fragment3 newInstance(String param1, String param2) {
        smoking_fragment3 fragment = new smoking_fragment3();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.smoking_fragment3, container, false);

        EditText editText10 = v.findViewById(R.id.editText10);
        ImageView imageView10 = v.findViewById(R.id.imageView10);
        imageView10.setVisibility(View.INVISIBLE);  //화면전환 직후에는 이미지가 보이지 않도록 한다. 초기값이 앱 아이콘이기 때문

        TextView textView12 = v.findViewById(R.id.textView12);
        TextView textView14 = v.findViewById(R.id.textView14);
        TextView textView16 = v.findViewById(R.id.textView16);
        TextView textView18 = v.findViewById(R.id.textView18);
        TextView textView20 = v.findViewById(R.id.textView20);


        Button button = v.findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int value = Integer.parseInt(editText10.getText().toString());  //하루 흡연량
                // ""를 넣지않으면 파라미터를 resource ID로 인식한다.
                textView12.setText("" + value * 225);
                textView14.setText("" + value * 225 * 30);
                textView16.setText("" + value * 225 * 365);
                textView18.setText("" + value * 225 * 365 * 10);
                textView20.setText("" + value * 225 * 365 * 30);

                imageView10.setVisibility(View.VISIBLE);    //이미지뷰를 보이도록 함
                int savings = value * 225 * 365 * 30 / 10000;       //만원 단위 버림

                if(savings <= 1480)
                    imageView10.setImageResource(R.drawable.morning);
                else if(savings > 1480 && savings <= 2779)
                    imageView10.setImageResource(R.drawable.avante);
                else if(savings > 2779 && savings <= 3642)
                    imageView10.setImageResource(R.drawable.sonata);
                else if(savings > 3642 && savings <= 4350)
                    imageView10.setImageResource(R.drawable.grandeur);
                else if(savings > 4350 && savings <= 5724)
                    imageView10.setImageResource(R.drawable.genisys);
                else if(savings > 5724)
                    imageView10.setImageResource(R.drawable.a5);
            }
        });
        // Inflate the layout for this fragment
        return v;
    }
}