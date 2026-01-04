package com.fzz.seal.entity;

import java.awt.*;

public class TextParams {
    private String[] text = null;
    private String textAlign = "left";
    private Color[] color = null;
    private String[] font = null;
    private double[] fontSize = null;
    private boolean[] isFontBold = null;
    private double[] lineSpacing = null;


    public double[] getLineSpacing() {
        return lineSpacing;
    }

    public void setLineSpacing(double[] lineSpacing) {
        this.lineSpacing = lineSpacing;
    }

    public String[] getText() {
        return text;
    }

    public void setText(String[] text) {
        this.text = text;
    }

    public String getTextAlign() {
        return textAlign;
    }

    public void setTextAlign(String textAlign) {
        this.textAlign = textAlign;
    }

    public Color[] getColor() {
        return color;
    }

    public void setColor(Color[] color) {
        this.color = color;
    }

    public String[] getFont() {
        return font;
    }

    public void setFont(String[] font) {
        this.font = font;
    }

    public double[] getFontSize() {
        return fontSize;
    }

    public void setFontSize(double[] fontSize) {
        this.fontSize = fontSize;
    }

    public boolean[] getIsFontBold() {
        return isFontBold;
    }

    public void setIsFontBold(boolean[] isFontBold) {
        this.isFontBold = isFontBold;
    }
}
