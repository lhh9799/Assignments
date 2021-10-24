package com.example.termproject;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class effectsAdapter extends RecyclerView.Adapter<effectsAdapter.ViewHolder>
        implements OneffectsItemClickListener {
    ArrayList<effects> items = new ArrayList<effects>();
    OneffectsItemClickListener listener;

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(viewGroup.getContext());
        View itemView = inflater.inflate(R.layout.effects_item, viewGroup, false);

        return new ViewHolder(itemView, this);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder viewHolder, int position) {
        effects item = items.get(position);
        viewHolder.setItem(item);
    }

    @Override
    public int getItemCount() {
        return items.size();
    }

    public void addItem(effects item) {
        items.add(item);
    }

    public void setItems(ArrayList<effects> items) {
        this.items = items;
    }

    public effects getItem(int position) {
        return items.get(position);
    }

    public void setItem(int position, effects item) {
        items.set(position, item);
    }

    public void setOnItemClickListener(OneffectsItemClickListener listener) {
        this.listener = listener;
    }

    //public void showDetails(effects item) {beginTransaction().replace(R.id.container, Fragment2).commit();}

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

        public ViewHolder(View itemView, final OneffectsItemClickListener listener) {
            super(itemView);

            textView2 = itemView.findViewById(R.id.textView31);
            textView3 = itemView.findViewById(R.id.textView32);
            imageView3 = itemView.findViewById(R.id.imageView);
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

        public void setItem(effects item) {
            textView2.setText(item.getOutline());
            textView3.setText(item.getBody());
            imageView3.setImageResource(item.getImgID());
        }
    }

}
