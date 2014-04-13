// http://www.careercup.com/question?id=6366101810184192
interface ICommand {
	public abstract void execute();
}

public class PowerOnCommand implements ICommand {
	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Power on.");
	}

}

public class PowerOffCommand implements ICommand {
	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Power off.");
	}
}

import java.util.Vector;

public class RemoteController {
	private Vector<ICommand> buttons;
	private String[] configuration = {"PowerOnCommand", "PowerOffCommand"};
	
	public RemoteController() {
		// TODO Auto-generated constructor stub
		buttons = new Vector<ICommand>();
		for (String commandType : configuration) {
			try {
				try {
					buttons.add((ICommand) Class.forName(commandType).newInstance());
				} catch (InstantiationException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IllegalAccessException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public void push(int commandIndex) {
		try {
			buttons.elementAt(commandIndex).execute();
		} catch (ArrayIndexOutOfBoundsException e) {
			// TODO: handle exception
		}
	}
}
