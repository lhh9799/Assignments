package org.techtown.travelapp;

import android.view.View;

public interface OnLandmarkItemClickListener {
    public void onItemClick(LandmarkAdapter.ViewHolder holder, View view, int position);
}
