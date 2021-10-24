package com.example.termproject;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.Arrays;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link smoking_fragment2#newInstance} factory method to
 * create an instance of this fragment.
 */
public class smoking_fragment2 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public smoking_fragment2() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment smoking_fragment2.
     */
    // TODO: Rename and change types and number of parameters
    public static smoking_fragment2 newInstance(String param1, String param2) {
        smoking_fragment2 fragment = new smoking_fragment2();
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
        View v = (View) inflater.inflate(R.layout.smoking_fragment2, container, false);
        recyclerView = (RecyclerView) v.findViewById(R.id.recyclerView2);

        //Fragment는 Activity가 아니기 때문에 MainActivity.this, 또는 this 사용이 안됨. 따라서 getActivity().getApplicationContext() 사용
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getActivity().getApplicationContext());
        recyclerView.setLayoutManager(linearLayoutManager);

        adapter = new change_effectAdapter();

        adapter.addItem(new change_effects("20분", "혈압과 맥박이 정상으로 돌아옵니다."));
        adapter.addItem(new change_effects("8시간","혈중 산소 농도가 정상으로 돌아오며 니코틴 및 일산화탄소 수치가 반 이상 줄어듭니다."));
        adapter.addItem(new change_effects("48시간", "체내의 니코틴이 완전히 사라집니다. 미각과 후각이 크게 개선됩니다."));
        adapter.addItem(new change_effects("72시간", "호흡이 수월해집니다. 기관지가 이완되며 몸에 활력이 돌기 시작합니다."));
        adapter.addItem(new change_effects("2~12주", "신체의 순환이 개선되면서 걷기와 뛰기가 수월해집니다."));
        adapter.addItem(new change_effects("3~9개월", "폐 기능이 최대 10%까지 좋아지면서 기침, 천명(쌕쌕거림), 호흡 곤란 등의 문제가 개선됩니다."));
        adapter.addItem(new change_effects("1년", "심장마비의 위험이 반으로 줄어듭니다."));
        adapter.addItem(new change_effects("5년", "심장마비의 위험이 일반 흡연자보다 반 이하로 줄어듭니다."));
        adapter.addItem(new change_effects("10년", "폐암 발병률이 일반 흡연자보다 반 이하로 줄어듭니다. 심장마비의 위험이 비흡연자와 동일한 수준으로 줄어듭니다."));

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
        // Inflate the layout for this fragment
//        return inflater.inflate(R.layout.fragment_fragment2, container, false);
    }
}