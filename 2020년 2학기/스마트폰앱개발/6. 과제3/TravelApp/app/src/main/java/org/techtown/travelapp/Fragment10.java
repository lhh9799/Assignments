package org.techtown.travelapp;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Fragment10#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment10 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;
    public static Landmark item;

    public Fragment10() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment10.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment10 newInstance(String param1, String param2) {
        Fragment10 fragment = new Fragment10();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    /*public static void receive(String Location, String Address) {
        this.Location = Location;
        Address = Address;
    }*/

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
        View v = (View) inflater.inflate(R.layout.landmark_detail, container, false);
        ImageView imageView3 = (ImageView) getView().findViewById(R.id.imageView3);
        TextView textView4 = (TextView) getView().findViewById(R.id.textView4);
        TextView textView5 = (TextView) getView().findViewById(R.id.textView5);
        TextView textView6 = (TextView) getView().findViewById(R.id.textView6);
        imageView3.setImageResource(R.drawable.berlin);
        textView4.setText("Berlin");
        textView5.setText("Pariser Platz, Germany");
        textView6.setText("베를린은 독일의 수도이다. 2014년 12월 현재 인구 3,562,166명으로, 독일 내 단일 규모로는 최대의 도시이고 유럽 연합(EU)의 최대 도시이기도 하다. 독일 북동부 슈프레강과 하펠강 연안에 있다. 도시 전체가 브란덴부르크주에 둘러싸여 있으며 베를린 자체도 연방주이다. 한자로 음차해서 백림 (伯林) 이라고도 한다.");
        // Inflate the layout for this fragment
        return v;
    }
}