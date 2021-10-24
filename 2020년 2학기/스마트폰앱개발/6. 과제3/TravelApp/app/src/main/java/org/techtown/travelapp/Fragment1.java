package org.techtown.travelapp;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.Arrays;
import java.util.List;
import java.util.Vector;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Fragment1#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment1 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Fragment1() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment1.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment1 newInstance(String param1, String param2) {
        Fragment1 fragment = new Fragment1();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        if (getArguments() != null) {
//            mParam1 = getArguments().getString(ARG_PARAM1);
//            mParam2 = getArguments().getString(ARG_PARAM2);
//        }

    }
    RecyclerView recyclerView;
    LandmarkAdapter adapter;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
//        LandmarkAdapter adapter;

        //프래그먼트에서는 findViewById 메소드를 사용할 수 없으므로 View객체에 현재 뷰를 담고 이를 이용하여 findViewById()를 호출
        View v = (View) inflater.inflate(R.layout.fragment_1, container, false);
        recyclerView = (RecyclerView) v.findViewById(R.id.recyclerView);

        //Fragment는 Activity가 아니기 때문에 MainActivity.this, 또는 this 사용이 안됨. 따라서 getActivity().getApplicationContext() 사용
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getActivity().getApplicationContext());
        recyclerView.setLayoutManager(linearLayoutManager);

        List<Integer> GermanyImgNo = Arrays.asList(R.drawable.berlin, R.drawable.heidelberg, R.drawable.bmw_museum, R.drawable.neuschwanstein_castle, R.drawable.frankfurt, R.drawable.isar);

        adapter = new LandmarkAdapter();

        //adapter.addItem(new TextView("Germany"));
        adapter.addItem(new Landmark("Berlin", "Pariser Platz, Germany", GermanyImgNo.get(0)));
        adapter.addItem(new Landmark("Heidelberg","Heidelberg, Germany", GermanyImgNo.get(1)));
        adapter.addItem(new Landmark("BMW Museum", "Am Olympiapark 2, 80809 München, Germany", GermanyImgNo.get(2)));
        adapter.addItem(new Landmark("Neuschwanstein Castle", "Hill castle in Schwangau, Germany", GermanyImgNo.get(3)));
        adapter.addItem(new Landmark("Frankfurt am Main", "Frankfurt, Germany", GermanyImgNo.get(4)));
        adapter.addItem(new Landmark("Isar", "Germany ~ Eiskarlspitze, Alps, Austria", GermanyImgNo.get(5)));

        recyclerView.setAdapter(adapter);

        /*adapter.setOnItemClickListener(new OnLandmarkItemClickListener() {
            @Override
            public void onItemClick(LandmarkAdapter.ViewHolder holder, View view, int position) {
                //Toast.makeText(getApplicationContext(), "터치됨", Toast.LENGTH_LONG).show();
                Landmark item = adapter.getItem(position);

//                Fragment10.ImgID = item.getImgID();
//                Fragment10.Location = item.getLocation();
//                Fragment10.Address = item.getAddress();
//                Fragment10.Detail = GermanyDetail.get(item.getImgID());


//                if(position == 0)
//                if (item.getImgID() == 0)
//                        getFragmentManager().beginTransaction().replace(R.id.container, new Fragment10()).commit();
                Toast.makeText(getActivity().getApplicationContext(), "아이템 선택됨 : " + item.getAddress(), Toast.LENGTH_LONG).show();
            }
        });*/
        return v;
        //자동완성 된 메소드라서 건드리지 않았는데 이게 문제였음. 4시간정도 지연됨
        //return inflater.inflate(R.layout.fragment_1, container, false);
    }
}