import com.fzz.seal.utils.FileOP;
import com.fzz.seal.*;

import java.text.SimpleDateFormat;
import java.util.Date;

//-Djava.library.path=/Users/zizhengfan/work/cpp/ofd/build/ofdcreate-dhssdygvturgepccmhnpnyoivmcu/Build/Products/Debug
public class test_OFDConverter {
    public static void main(String agrs[]) throws Exception {
        long currtime = System.currentTimeMillis();
        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 开始执行-------  ");

        //ofd2image_zip();
        //ofd2image();
        //ofd2image_page();
        //ofd2pdf();
        ofd2pdf_Handle();
        //ofd2image_page_Handle();
        //ofd2image_Handle();
        //ofd2image_zip_handle();

        System.out.println(new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss:SSS").format(new Date())
                +" ----- 结束执行------- 总耗时: "+ (System.currentTimeMillis() - currtime) );
    }

//    public static void ofd2image_zip() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        String filename = "/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/OFDSign.ofd";
//        //String filename = "/Users/zizhengfan/work/cpp/ofd/tmp/ofd/a4d91187d44e4d8baa56612132667196_2.ofd";
//        byte[] ofdata = fileOP.ReadFile(filename);
//        byte[] imagedata = OFDConverter.ofd2ImageToZip(ofdata,"JPG");
//
//        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/doc.zip",imagedata);
//
//    }

    public static void ofd2image_zip_handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        String filename = "/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd";
        byte[] ofdata = fileOP.ReadFile(filename);
        long handle = OFD.open(ofdata);
        if ( handle != 0 ) {
            byte[] imagedata = OFDConverter.ofd2ImageZip(handle, "SVG",1);

            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/doc.zip", imagedata);
            OFD.close(handle);
        }
    }

//    public static void ofd2image() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/ofd/a4d91187d44e4d8baa56612132667196_2.ofd");
//        byte[][] imagedata = OFDConverter.ofd2Image(ofdata,"JPG");
//
//        for (int i = 0; i < imagedata.length; i++ ) {
//            fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/doc_"+i+".jpg",imagedata[i]);
//        }
//    }

    public static void ofd2image_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd");
        long handle = OFD.open(ofdata);
        if ( handle != 0 ) {
            byte[][] imagedata = OFDConverter.ofd2Image(handle, "SVG",1);

            for (int i = 0; i < imagedata.length; i++) {
                fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/doc_" + i + ".svg", imagedata[i]);
            }

            OFD.close(handle);
        }
    }

//    public static void ofd2image_page() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/ofd/a4d91187d44e4d8baa56612132667196_2.ofd");
//        long count = OFDConverter.getOFDPageCount(ofdata);
//
//
//        for (int i = 0; i < count; i++ ) {
//            byte[] imagedata = OFDConverter.ofdPage2Image(ofdata,"JPG",i);
//            fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/docpage_"+i+".jpg",imagedata);
//        }
//    }

    public static void ofd2image_page_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd");
        long handle = OFD.open(ofdata);
        if ( handle != 0 ) {
            long count = OFD.getOfdPageCount(handle);
            for (int i = 0; i < count; i++) {
                byte[] imagedata = OFDConverter.ofdPage2Image(handle, "SVG", i,1);
                fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/docpage_" + i + ".svg", imagedata);
            }
            OFD.close(handle);
        }
    }

//    public static void ofd2pdf() throws Exception
//    {
//        FileOP fileOP = new FileOP();
//        byte[] ofdata = fileOP.ReadFile("/Users/zizhengfan/work/cpp/ofd/tmp/ofd/a4d91187d44e4d8baa56612132667196_2.ofd");
//        byte[] imagedata = OFDConverter.ofd2PDF(ofdata,false);
//
//        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/doc_stamp.pdf",imagedata);
//        imagedata = OFDConverter.ofd2PDF(ofdata,true);
//
//        fileOP.WriteFile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/test/doc.pdf",imagedata);
//
//    }

    public static void ofd2pdf_Handle() throws Exception
    {
        FileOP fileOP = new FileOP();
        byte[] ofdata = fileOP.ReadFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/OFDSign.ofd");
        long handle = OFD.open(ofdata);
        if ( handle != 0 ) {
            //byte[] imagedata = OFDConverter.ofd2Pdf(handle,false,false,"");
            //byte[] imagedata = OFDConverter.ofd2Pdf(handle,false,true,"");
            byte[] imagedata = OFDConverter.ofd2Pdf(handle,false,false,"12345678");
            fileOP.WriteFile("/Volumes/WorkExt/work/cpp/ofdpdfsigner_test/imageconverter/doc_stamp.pdf", imagedata);
            //imagedata = OFDConverter.ofd2Pdf(handle, true);

            //fileOP.WriteFile("/Users/zizhengfan/work/work_cpp/ofdpdfsigner_test/imageconverter/doc.pdf", imagedata);

            OFD.close(handle);
        }
    }
}
