package com.wilutions.jsfs;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class DlgCredentials {
  
  public static boolean showDialog(String[] args) {
    JTextField edUserName = new JTextField(10);
    JPasswordField edPassword = new JPasswordField(10);

    // My Swing knowledge is really poor.
    // How can the Name and Password input boxes 
    // be aligned vertically?
    
    JPanel myPanel = new JPanel();
    myPanel.add(new JLabel("Name:"));
    myPanel.add(edUserName);
    myPanel.add(new JLabel("Password:"));
    myPanel.add(edPassword);

    int result = JOptionPane.showConfirmDialog(null, myPanel, 
             "Please Enter Name and Password", JOptionPane.OK_CANCEL_OPTION);
    
    args[0] = edUserName.getText();
    args[1] = new String(edPassword.getPassword());

    return result == JOptionPane.OK_OPTION;
 }
}
