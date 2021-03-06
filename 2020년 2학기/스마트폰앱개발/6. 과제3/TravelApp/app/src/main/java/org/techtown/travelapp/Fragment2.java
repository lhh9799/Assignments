package org.techtown.travelapp;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import java.util.Arrays;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Fragment2#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment2 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Fragment2() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment2.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment2 newInstance(String param1, String param2) {
        Fragment2 fragment = new Fragment2();
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
    RecyclerView recyclerView2;
    LandmarkAdapter adapter;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
//        LandmarkAdapter adapter;

        //???????????????????????? findViewById ???????????? ????????? ??? ???????????? View????????? ?????? ?????? ?????? ?????? ???????????? findViewById()??? ??????
        View v = (View) inflater.inflate(R.layout.fragment_2, container, false);
        recyclerView2 = (RecyclerView) v.findViewById(R.id.recyclerView2);

        //Fragment??? Activity??? ????????? ????????? MainActivity.this, ?????? this ????????? ??????. ????????? getActivity().getApplicationContext() ??????
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getActivity().getApplicationContext());
        recyclerView2.setLayoutManager(linearLayoutManager);

        List<Integer> FranceImgNo = Arrays.asList(R.drawable.strasbourg, R.drawable.mont_blanc, R.drawable.louvre_museum, R.drawable.eiffel_tower, R.drawable.champs_elysees, R.drawable.notre_dame_de_paris);

        adapter = new LandmarkAdapter();

        //adapter.addItem(new TextView("Germany"));
        adapter.addItem(new Landmark("Strasbourg", "Strasbourg", FranceImgNo.get(0)));
        adapter.addItem(new Landmark("Mont Blanc","Auvergne-Rh??ne-Alpes, France ~ Aosta Valley, Italy", FranceImgNo.get(1)));
        adapter.addItem(new Landmark("Louvre Museum", "Rue de Rivoli, 75001 Paris, France", FranceImgNo.get(2)));
        adapter.addItem(new Landmark("The Eiffel Tower", "Champ de Mars, 5 Avenue Anatole France, 75007 Paris, France", FranceImgNo.get(3)));
        adapter.addItem(new Landmark("Champs-??lys??es", "Av. des Champs-??lys??es75008 Paris, France", FranceImgNo.get(4)));
        adapter.addItem(new Landmark("Notre-Dame de Paris", "6 Parvis Notre-Dame - Pl. Jean-Paul II, 75004 Paris, France", FranceImgNo.get(5)));

        recyclerView2.setAdapter(adapter);

        adapter.setOnItemClickListener(new OnLandmarkItemClickListener() {
            @Override
            public void onItemClick(LandmarkAdapter.ViewHolder holder, View view, int position) {
                //Toast.makeText(getApplicationContext(), "?????????", Toast.LENGTH_LONG).show();
                Landmark item = adapter.getItem(position);

                Toast.makeText(getActivity().getApplicationContext(), "????????? ????????? : " + item.getAddress(), Toast.LENGTH_LONG).show();
            }
        });
        return v;
        //???????????? ??? ??????????????? ???????????? ???????????? ?????? ????????????. 4???????????? ?????????
        //return inflater.inflate(R.layout.fragment_1, container, false);
    }
}