package com.example.termproject;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link smoking_fragment4#newInstance} factory method to
 * create an instance of this fragment.
 */
public class smoking_fragment4 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public smoking_fragment4() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment smoking_fragment4.
     */
    // TODO: Rename and change types and number of parameters
    public static smoking_fragment4 newInstance(String param1, String param2) {
        smoking_fragment4 fragment = new smoking_fragment4();
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

    RecyclerView recyclerView;
    change_effectAdapter adapter;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        //프래그먼트에서는 findViewById 메소드를 사용할 수 없으므로 View객체에 현재 뷰를 담고 이를 이용하여 findViewById()를 호출
        View v = (View) inflater.inflate(R.layout.smoking_fragment4, container, false);
        recyclerView = (RecyclerView) v.findViewById(R.id.recyclerView3);

        //Fragment는 Activity가 아니기 때문에 MainActivity.this, 또는 this 사용이 안됨. 따라서 getActivity().getApplicationContext() 사용
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getActivity().getApplicationContext());
        recyclerView.setLayoutManager(linearLayoutManager);

        adapter = new change_effectAdapter();

        adapter.addItem(new change_effects("광주금연지원센터", "광주광역시 동구 필문대로365 조선대학교병원 본관 2층\n062-222-9030"));
        adapter.addItem(new change_effects("광주 동구보건소", "광주광역시 동구 서남로 1 (서석동)\n062-608-3371"));
        adapter.addItem(new change_effects("광주 광산구보건소","광주광역시 광산구 광산로29번길 15 (833-8번지, 송정동)\n062-960-8805 "));
        adapter.addItem(new change_effects("광주 북구보건소", "광주광역시 북구 우치로 65(중흥동)\n062-410-8977"));
        adapter.addItem(new change_effects("광주 서구보건소", "광주광역시 서구 경열로 33(농성동)\n062-350-4128"));

        recyclerView.setAdapter(adapter);

//        adapter.setOnItemClickListener(new OneffectsItemClickListener() {
//            @Override
//            public void onItemClick(effectsAdapter.ViewHolder holder, View view, int position) {
//                //Toast.makeText(getApplicationContext(), "터치됨", Toast.LENGTH_LONG).show();
//                effects item = adapter.getItem(position);
//
//                Toast.makeText(getActivity().getApplicationContext(), "아이템 선택됨 : " + item.getOutline(), Toast.LENGTH_LONG).show();
//            }
//        });
        return v;
//        // Inflate the layout for this fragment
//        return inflater.inflate(R.layout.smoking_fragment4, container, false);
    }
}