package org.cocos2dx.cpp.drawingcoloring.utility;

import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Typeface;

public class Font {
    private static Font _self = null;
    private Typeface mTodoSchoolV3 = null;

    private Font(Context context) {
        AssetManager mgr = context.getAssets();
        mTodoSchoolV3 = Typeface.createFromAsset(mgr, "font/TodoSchoolV3.ttf");

        if (mTodoSchoolV3 == null) {
            mTodoSchoolV3 = Typeface.DEFAULT;
        }
    }

    public static Font getInstance(Context context) {
        if (null == _self) _self = new Font(context);
        return _self;
    }

    public Typeface getTodoSchoolV3() {
        return mTodoSchoolV3;
    }
}