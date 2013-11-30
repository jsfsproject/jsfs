package com.wilutions.jsfs;

import java.awt.AWTException;
import java.awt.Image;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.awt.SystemTray;
import java.awt.TrayIcon;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

/**
 * This class provides an icon that is shown in the system tray.
 *
 */
public class JsfsTrayIcon {
  
  private TrayIcon trayIcon;
  private Image normalImage;
  private Image inUseImage;
  private long inUseImageVisibleUntilSystemMillis;
  private Timer imageTimer;
  private String appName = "JavaScript File System Adapter";
  
  public void showError(Throwable ex) {
    trayIcon.displayMessage(appName, ex.toString(), TrayIcon.MessageType.ERROR);
  }
  
  public void showInfo(String msg) {
    trayIcon.displayMessage(appName, msg, TrayIcon.MessageType.INFO);
  }
  
  public static JsfsTrayIcon createAndShowGUI() {
    JsfsTrayIcon inst = new JsfsTrayIcon();
    inst.internalCreateAndShowGUI();
    return inst;
  }
  
  private void internalCreateAndShowGUI() {
    
    // Check the SystemTray support
    if (!SystemTray.isSupported()) {
      throw new IllegalStateException("SystemTray is not supported");
    }
    
    normalImage = createImage("Debug-External-link-icon.png", "Normal");
    inUseImage = createImage("Debug-External-link-icon.png", "In use");
    
    final PopupMenu popup = new PopupMenu();
    trayIcon = new TrayIcon(normalImage);
    trayIcon.setImageAutoSize(true);
    final SystemTray tray = SystemTray.getSystemTray();

    // Create a popup menu components
    MenuItem aboutItem = new MenuItem("About");
//    CheckboxMenuItem cb1 = new CheckboxMenuItem("Set auto size");
//    CheckboxMenuItem cb2 = new CheckboxMenuItem("Set tooltip");
//    Menu displayMenu = new Menu("Display");
//    MenuItem errorItem = new MenuItem("Error");
//    MenuItem warningItem = new MenuItem("Warning");
//    MenuItem infoItem = new MenuItem("Info");
//    MenuItem noneItem = new MenuItem("None");
    MenuItem exitItem = new MenuItem("Exit");

    // Add components to popup menu
    popup.add(aboutItem);
//    popup.addSeparator();
//    popup.add(cb1);
//    popup.add(cb2);
//    popup.addSeparator();
//    popup.add(displayMenu);
//    displayMenu.add(errorItem);
//    displayMenu.add(warningItem);
//    displayMenu.add(infoItem);
//    displayMenu.add(noneItem);
    popup.add(exitItem);

    trayIcon.setPopupMenu(popup);

    try {
      tray.add(trayIcon);
    } catch (AWTException e) {
      System.out.println("TrayIcon could not be added.");
      return;
    }

    trayIcon.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        JOptionPane.showMessageDialog(null, "This dialog box is run from System Tray");
      }
    });

    aboutItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        JOptionPane.showMessageDialog(null, appName);
      }
    });

//    cb1.addItemListener(new ItemListener() {
//      public void itemStateChanged(ItemEvent e) {
//        int cb1Id = e.getStateChange();
//        if (cb1Id == ItemEvent.SELECTED) {
//          trayIcon.setImageAutoSize(true);
//        }
//        else {
//          trayIcon.setImageAutoSize(false);
//        }
//      }
//    });
//
//    cb2.addItemListener(new ItemListener() {
//      public void itemStateChanged(ItemEvent e) {
//        int cb2Id = e.getStateChange();
//        if (cb2Id == ItemEvent.SELECTED) {
//          trayIcon.setToolTip("Sun TrayIcon");
//        }
//        else {
//          trayIcon.setToolTip(null);
//        }
//      }
//    });
//
//    ActionListener listener = new ActionListener() {
//      public void actionPerformed(ActionEvent e) {
//        MenuItem item = (MenuItem) e.getSource();
//        // TrayIcon.MessageType type = null;
//        System.out.println(item.getLabel());
//        if ("Error".equals(item.getLabel())) {
//          // type = TrayIcon.MessageType.ERROR;
//          trayIcon.displayMessage("Sun TrayIcon Demo", "This is an error message", TrayIcon.MessageType.ERROR);
//
//        }
//        else if ("Warning".equals(item.getLabel())) {
//          // type = TrayIcon.MessageType.WARNING;
//          trayIcon.displayMessage("Sun TrayIcon Demo", "This is a warning message", TrayIcon.MessageType.WARNING);
//
//        }
//        else if ("Info".equals(item.getLabel())) {
//          // type = TrayIcon.MessageType.INFO;
//          trayIcon.displayMessage("Sun TrayIcon Demo", "This is an info message", TrayIcon.MessageType.INFO);
//
//        }
//        else if ("None".equals(item.getLabel())) {
//          // type = TrayIcon.MessageType.NONE;
//          trayIcon.displayMessage("Sun TrayIcon Demo", "This is an ordinary message", TrayIcon.MessageType.NONE);
//        }
//      }
//    };
//
//    errorItem.addActionListener(listener);
//    warningItem.addActionListener(listener);
//    infoItem.addActionListener(listener);
//    noneItem.addActionListener(listener);
//
    exitItem.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        tray.remove(trayIcon);
        System.exit(0);
      }
    });
  }

  // Obtain the image URL
  protected static Image createImage(String path, String description) {
    URL imageURL = JsfsTrayIcon.class.getResource(path);

    if (imageURL == null) {
      System.err.println("Resource not found: " + path);
      return null;
    }
    else {
      return (new ImageIcon(imageURL, description)).getImage();
    }

  }
  
  private void internalTouch() {
    
    if (inUseImageVisibleUntilSystemMillis < System.currentTimeMillis()) {
      
      trayIcon.setImage(inUseImage);
      
      // Start timer to reset image
      if (imageTimer == null) {
        ActionListener taskPerformer = new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
              if (inUseImageVisibleUntilSystemMillis < System.currentTimeMillis() 
                  && trayIcon.getImage() != normalImage) {
                trayIcon.setImage(normalImage);
              }
            }
        };
        imageTimer = new Timer(500, taskPerformer);
        imageTimer.start();
      }
    }
    
    inUseImageVisibleUntilSystemMillis = System.currentTimeMillis() + 1000;

  }

  public void touch() {
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        internalTouch();
      }
    });
  }
}