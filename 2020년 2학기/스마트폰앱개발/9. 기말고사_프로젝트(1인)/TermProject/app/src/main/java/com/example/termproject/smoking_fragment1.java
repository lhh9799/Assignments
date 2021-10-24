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
 * Use the {@link smoking_fragment1#newInstance} factory method to
 * create an instance of this fragment.
 */
public class smoking_fragment1 extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public smoking_fragment1() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment smoking_fragment1.
     */
    // TODO: Rename and change types and number of parameters
    public static smoking_fragment1 newInstance(String param1, String param2) {
        smoking_fragment1 fragment = new smoking_fragment1();
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
    effectsAdapter adapter;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        //프래그먼트에서는 findViewById 메소드를 사용할 수 없으므로 View객체에 현재 뷰를 담고 이를 이용하여 findViewById()를 호출
        View v = (View) inflater.inflate(R.layout.smoking_fragment1, container, false);
        recyclerView = (RecyclerView) v.findViewById(R.id.recyclerView);

        //Fragment는 Activity가 아니기 때문에 MainActivity.this, 또는 this 사용이 안됨. 따라서 getActivity().getApplicationContext() 사용
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getActivity().getApplicationContext());
        recyclerView.setLayoutManager(linearLayoutManager);

        List<Integer> ImgNo = Arrays.asList(R.drawable.smoking_smell_crop, R.drawable.no_coughing, R.drawable.handful_cigarettes, R.drawable.money_saving, R.drawable.tasting, R.drawable.restaurant_reeptionists, R.drawable.artificial_tears, R.drawable.yellow_teeth, R.drawable.wonbin, R.drawable.work_faster);

        adapter = new effectsAdapter();

        adapter.addItem(new effects("1. 불쾌한 냄새에서 해방", "차와 집, 옷, 심지어 애완견에게도 배어 있는 고약한 담배 냄새에서 탈출할 수 있다. 물론 담배를 끊고 나서야 자신이 그 지독한 냄새와 항상 함께했다는 사실을 깨닫게 된다.", ImgNo.get(0)));
        adapter.addItem(new effects("2. 만성 기침에서 해방","담배를 피우는 사람은 누구나 ‘흡연자 기침’을 하게 된다. 그런데 담배를 끊기 전까지는 그 기침이 얼마나 귀찮은 것인지 잘 모른다.", ImgNo.get(1)));
        adapter.addItem(new effects("3. 담배꽁초 치우기 그만", "흡연자 주변 곳곳에 숨어 있는 담배꽁초들. 꽁초들에서 벗어난다는 것은 그만큼 귀찮은 청소를 하지 않아도 된다는 뜻이다.", ImgNo.get(2)));
        adapter.addItem(new effects("4. 담배 값 절약", "별 생각 없이 지출하는 담배 값. 담배를 끊으면 실질적 이익으로 돈을 절약할 수 있다. 만약 4500원 하는 담배 한 갑을 일주일에 네 갑 정도 피운다면 한 달에 7만 2000원, 1년이면 86만 4000원 정도의 보너스를 얻는 것이다.", ImgNo.get(3)));
        adapter.addItem(new effects("5. 음식 맛이 좋아진다", "입 안이 깨끗해지면서 음식 맛도 더 좋아진다. 예전보다 소금도 덜 먹게 된다. 담배를 끊으면 살이 찐다고들 하지만, 금연을 한 번 시도해 본 뒤에 걱정해도 될 일이다.", ImgNo.get(4)));
        adapter.addItem(new effects("6. 대접을 받는다", "이제는 ‘흡연’이나 ‘비흡연’을 묻는 질문 대신 비흡연자들만을 상대로 한 질문을 듣게 될지 모른다. 더 이상 흡연자를 위한 공간은 없다. 예전에는 담배를 피우는 것이 상위계층의 고급문화로 여기기도 했지만, 이제는 모든 공공장소가 금연 구역이 되고 있다.", ImgNo.get(5)));
        adapter.addItem(new effects("7. 편안한 콘택트렌즈", "담배를 피우면 콘택트렌즈가 건조해진다. 구름이 낀 듯 뿌옇게 흐려지는 시야 때문에 눈을 자꾸 문지르게 되고 결국 렌즈를 뺄 수밖에 없다.", ImgNo.get(6)));
        adapter.addItem(new effects("8. 누런 치아와 결별", "수없이 양치질을 해도 하얘지지 않는 누런 치아. 지저분한 치아는 보기에도 나쁘지만, 전반적인 건강에도 해롭다. 담배를 끊으면 한결 깨끗해진 치아를 가질 수 있다.", ImgNo.get(7)));
        adapter.addItem(new effects("9. 외모도 달라진다", "담배를 끊고 몇 달 지나지 않아도 외모가 달라진다는 것을 알 수 있다. 피부가 건조하지 않고 주름도 덜하다. 때로 흰 머리가 덜 나기도 한다. 숨 쉴 때마다 담배 냄새 때문에 다른 사람에게 신경을 덜 써도 되므로 자신감도 생긴다.", ImgNo.get(8)));
        adapter.addItem(new effects("10. 생산성 향상", "누구에게나 휴식은 필요하다. 하루 종일 일만 할 수 없기 때문이다. 다른 사람들은 5분 정도 휴식을 취할 때 흡연자들은 10분 이상 쉬게 된다. 많을 경우 하루 2시간을 담배 피우는데 소비하기도 한다. 또한 담배를 피우느라 일을 하다가도 쉬어야 하므로 생산성이 떨어진다.", ImgNo.get(9)));

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
        //return inflater.inflate(R.layout.fragment_1, container, false);
//        // Inflate the layout for this fragment
//        return inflater.inflate(R.layout.smoking_fragment1, container, false);
    }
}