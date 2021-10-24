package com.example.termproject;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapView;
import com.google.android.gms.maps.MapsInitializer;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;
//권한 여부를 사용자에게 묻는 작업을 자동으로 해주는 라이브러리
import com.pedro.library.AutoPermissions;

//public class Map extends AppCompatActivity {
public class Map extends Fragment implements OnMapReadyCallback {
//    SupportMapFragment mapFragment;
    View v;
    MapView mapView;
    GoogleMap map;
    MarkerOptions myLocationMarker;

    public Map() { }

    @Override
    public void onCreateOptionsMenu(Menu menu, MenuInflater menuInflater) { }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        setHasOptionsMenu(true);
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.map_fragment);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        //프래그먼트에서는 findViewById 메소드를 사용할 수 없으므로 View객체에 현재 뷰를 담고 이를 이용하여 findViewById()를 호출
//        v = (View) inflater.inflate(R.layout.smoking_fragment1, container, false);
        v = inflater.inflate(R.layout.smoking_fragment1, container, false);

        mapView = (MapView) v.findViewById(R.id.map);
        mapView.onCreate(savedInstanceState);
        mapView.getMapAsync(this);
//        mapView.getMapAsync(new OnMapReadyCallback() {
//            @Override
//            public void onMapReady(GoogleMap googleMap) {
//                Log.d("Map", "지도 준비됨.");
//                map = googleMap;
//            }
//        });
//
//        try {
//            MapsInitializer.initialize(getContext());
//        } catch (Exception e) {
//            e.printStackTrace();
//        }

//        Button button20 = getActivity().findViewById(R.id.button20);
//        button20.setOnClickListener(new View.OnClickListener() {
//            public void onClick(View v) {
//                startLocationService();
//            }
//        });

        AutoPermissions.Companion.loadAllPermissions(getActivity(), 101);

        return v;
    }

    @Override
    public void onSaveInstanceState(Bundle outstate) {
        super.onSaveInstanceState(outstate);
        mapView.onSaveInstanceState(outstate);
    }

    @Override
    public void onPause() {
        super.onPause();
        mapView.onPause();
    }

    @Override
    public void onResume() {
        super.onResume();
        mapView.onResume();
    }

    @Override
    public void onLowMemory() {
        super.onLowMemory();
        mapView.onLowMemory();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        mapView.onDestroy();
    }

//    public void startLocationService() {
//        LocationManager manager = (LocationManager) getActivity().getSystemService(Context.LOCATION_SERVICE);
//
//        try {
//            Location location = manager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
//            if (location != null) {
//                double latitude = location.getLatitude();
//                double longtitude = location.getLongitude();
//                String message = "최근 위치-> Latitude : " + latitude + "\nLongtitude:" + longtitude;
//
////                textView.setText(message);
//            }
//
////            GPSListener gpsListener = new GPSListener();    //리스너 객체 생성
////            long minTime = 10000;   //10초마다
////            float minDistance = 0;  //거리이동 0마다
//
////            manager.requestLocationUpdates(LocationManager.GPS_PROVIDER, minTime, minDistance, gpsListener);
////            Toast.makeText(getActivity().getApplicationContext(), "내 위치 확인 요청함", Toast.LENGTH_SHORT).show();
//        } catch(SecurityException e) {
//                e.printStackTrace();
//        }
//    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        MapsInitializer.initialize(getActivity().getApplicationContext());
    }

//    class GPSListener implements LocationListener {
//        public void onLocationChanged(Location location) {  //위치가 확인되었을 때 자동으로 호출되는 onLocationChanged() 메소드
//            Double latitude = location.getLatitude();
//            Double longtitude = location.getLatitude();
//            String message = "내 위치 -> Latitude : " + latitude + "\nLongtitude:" + longtitude;
////          textView.setText(message);
//            showCurrentLocation(latitude, longtitude);
//        }
//
//        public void onProviderDisabled(String provider) {
//        }
//
//        public void onProviderEnabled(String provider) {
//        }
//
//        public void onStatusChanged(String provider, int status, Bundle extras) {
//        }
//        private void showCurrentLocation(Double latitude, Double longtitude) {
//            LatLng curPoint = new LatLng(latitude, longtitude); //현재 위치 좌표로 LatLng 객체 생성하기
//            map.animateCamera(CameraUpdateFactory.newLatLngZoom(curPoint, 15));
//
//            showMyLocationMarker(curPoint);
//        }
//        private void showMyLocationMarker(LatLng curPoint) {
//            if(myLocationMarker == null) {
//                myLocationMarker = new MarkerOptions();
//                myLocationMarker.position(curPoint);
//                myLocationMarker.title("내 위치\n");
//                myLocationMarker.snippet("GPS로 확인한 위치");
//                myLocationMarker.icon(BitmapDescriptorFactory.fromResource(R.drawable.mylocation));
//            }
//        }
//    }
}