package com.example.termproject;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class change_effectAdapter extends RecyclerView.Adapter<change_effectAdapter.ViewHolder>
        implements Onchange_effectItemClickListener {
    ArrayList<change_effects> items = new ArrayList<change_effects>();
    Onchange_effectItemClickListener listener;

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(viewGroup.getContext());
        View itemView = inflater.inflate(R.layout.change_effect, viewGroup, false);

        return new ViewHolder(itemView, this);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder viewHolder, int position) {
        change_effects item = items.get(position);
        viewHolder.setItem(item);
    }

    @Override
    public int getItemCount() {
        return items.size();
    }

    public void addItem(change_effects item) {
        items.add(item);
    }

    public void setItems(ArrayList<change_effects> items) {
        this.items = items;
    }

    public change_effects getItem(int position) {
        return items.get(position);
    }

    public void setItem(int position, change_effects item) {
        items.set(position, item);
    }

    public void setOnItemClickListener(Onchange_effectItemClickListener listener) {
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
        TextView textView3;
        TextView textView4;

        public ViewHolder(View itemView, final Onchange_effectItemClickListener listener) {
            super(itemView);

            textView3 = itemView.findViewById(R.id.textArea1);
            textView4 = itemView.findViewById(R.id.textArea2);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    int position = getAdapterPosition();
//                    FragmentManager fragmentManager = ((Activity3) context).getSupportFragmentManager();

                    if (listener != null) {
                        listener.onItemClick(ViewHolder.this, view, position);
                    }
                }
            });
        }

        public void setItem(change_effects item) {
            textView3.setText(item.getOutline());
            textView4.setText(item.getBody());
        }
    }

}
