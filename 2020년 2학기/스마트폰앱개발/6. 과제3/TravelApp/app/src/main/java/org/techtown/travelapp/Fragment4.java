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
 * Use the {@link Fragment4#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment4 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Fragment4() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment4.
     */
    // TODO: Rename and change types and number of parameters
    public static Fragment4 newInstance(String param1, String param2) {
        Fragment4 fragment = new Fragment4();
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
    RecyclerView recyclerView4;
    LandmarkAdapter adapter;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
//        LandmarkAdapter adapter;

        //프래그먼트에서는 findViewById 메소드를 사용할 수 없으므로 View객체에 현재 뷰를 담고 이를 이용하여 findViewById()를 호출
        View v = (View) inflater.inflate(R.layout.fragment_4, container, false);
        recyclerView4 = (RecyclerView) v.findViewById(R.id.recyclerView4);

        //Fragment는 Activity가 아니기 때문에 MainActivity.this, 또는 this 사용이 안됨. 따라서 getActivity().getApplicationContext() 사용
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getActivity().getApplicationContext());
        recyclerView4.setLayoutManager(linearLayoutManager);

        List<Integer> CafeImgNo = Arrays.asList(R.drawable.starbucks_yangpyeong_dtr, R.drawable.bukchon_coffee_mill, R.drawable.bluebottle_seongsu, R.drawable.cafe_liebeliebe, R.drawable.hack_coffee);

        adapter = new LandmarkAdapter();

        //adapter.addItem(new TextView("Germany"));
        adapter.addItem(new Landmark("스타벅스 더양평DTR", "경기도 양평군 양평읍 양근로 76", CafeImgNo.get(0)));
        adapter.addItem(new Landmark("커피방앗간","서울특별시 종로구 화동 북촌로5가길 8-11", CafeImgNo.get(1)));
        adapter.addItem(new Landmark("블루보틀 성수", "서울특별시 성동구 성수동1가 아차산로 7", CafeImgNo.get(2)));
        adapter.addItem(new Landmark("카페리베리베", "울산광역시 울주군 서생면 간절곶1길 8", CafeImgNo.get(3)));
        adapter.addItem(new Landmark("홍대 핵커피(폐업)", "서울특별시 서대문구 대현동 56-2", CafeImgNo.get(4)));

        recyclerView4.setAdapter(adapter);

        adapter.setOnItemClickListener(new OnLandmarkItemClickListener() {
            @Override
            public void onItemClick(LandmarkAdapter.ViewHolder holder, View view, int position) {
                //Toast.makeText(getApplicationContext(), "터치됨", Toast.LENGTH_LONG).show();
                Landmark item = adapter.getItem(position);

                Toast.makeText(getActivity().getApplicationContext(), "아이템 선택됨 : " + item.getAddress(), Toast.LENGTH_LONG).show();
            }
        });
        return v;
        //자동완성 된 메소드라서 건드리지 않았는데 이게 문제였음. 4시간정도 지연됨
        //return inflater.inflate(R.layout.fragment_1, container, false);
    }
}