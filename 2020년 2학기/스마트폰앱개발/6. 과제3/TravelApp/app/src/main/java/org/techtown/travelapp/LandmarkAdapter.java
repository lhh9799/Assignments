package org.techtown.travelapp;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.fragment.app.FragmentManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class LandmarkAdapter extends RecyclerView.Adapter<LandmarkAdapter.ViewHolder>
        implements OnLandmarkItemClickListener {
    ArrayList<Landmark> items = new ArrayList<Landmark>();
    OnLandmarkItemClickListener listener;

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(viewGroup.getContext());
        View itemView = inflater.inflate(R.layout.landmark_item, viewGroup, false);

        return new ViewHolder(itemView, this);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder viewHolder, int position) {
        Landmark item = items.get(position);
        viewHolder.setItem(item);
    }

    @Override
    public int getItemCount() {
        return items.size();
    }

    public void addItem(Landmark item) {
        items.add(item);
    }

    public void setItems(ArrayList<Landmark> items) {
        this.items = items;
    }

    public Landmark getItem(int position) {
        return items.get(position);
    }

    public void setItem(int position, Landmark item) {
        items.set(position, item);
    }

    public void setOnItemClickListener(OnLandmarkItemClickListener listener) {
        this.listener = listener;
    }

    //public void showDetails(Landmark item) {beginTransaction().replace(R.id.container, Fragment2).commit();}

    @Override
    public void onItemClick(ViewHolder holder, View view, int position) {
        if (listener != null) {
            listener.onItemClick(holder, view, position);
        }
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        TextView textView2;
        TextView textView3;
        ImageView imageView3;
//        Fragment10 Fragment10;
//        Context context;

        public ViewHolder(View itemView, final OnLandmarkItemClickListener listener) {
            super(itemView);

            textView2 = itemView.findViewById(R.id.textView2);
            textView3 = itemView.findViewById(R.id.textView3);
            imageView3 = itemView.findViewById(R.id.imageView3);
//            Fragment10 = new Fragment10();

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    int position = getAdapterPosition();
//                    FragmentManager fragmentManager = ((Activity3) context).getSupportFragmentManager();

                    if (listener != null) {
                        listener.onItemClick(ViewHolder.this, view, position);
                    }
                    //완전한 해결방법이 아님 -> 어차피 해결도 안됨
//                    switch (position) {
//                        case 0 : fragmentManager.beginTransaction().replace(R.id.container, Fragment10).commit();
//                    }
                }
            });
        }

        public void setItem(Landmark item) {
            textView2.setText(item.getLocation());
            textView3.setText(item.getAddress());
            imageView3.setImageResource(item.getImgID());
        }
    }

}
