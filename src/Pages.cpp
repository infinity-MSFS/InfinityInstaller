#include "Pages.h"

#include "ApplicationGUI.h"
#include "Components/PreDefCursorPositions.h"

Pages::Pages::Pages() {
}

void Pages::Pages::NextPage() {
	s_currentPage++;
}

void Pages::Pages::PrevPage() {
	s_currentPage--;
}

void Pages::Pages::RenderPageContent() {
	GetPageContent(intToPage(s_currentPage));
}

static float percentage = 0.0;

void Pages::Pages::GetPageContent(Page page) {
	switch (page) {
		case Page::Welcome: {
			ImGui::Text("Welcum to Infinity Launcher");

			ImGui::SetCursorPos(PredefinedCursorPositions::bottomLeftButton);
			if (ImGui::Button("Exit")) {
				Walnut::Application::Get().Close();
			}

			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightButton);
			if (ImGui::Button("Next")) {
				NextPage();
			}
		}
		break;
		case Page::License: {
			ImGui::SetCursorPos(ImVec2(170.0, 10.0));
			ImGui::Text("License Agreement");

			static bool accepted = false;

			ImGui::SetCursorPos(ImVec2(100.0, 370.0));
			ImGui::Checkbox("Accept License Agreement", &accepted);


			ImGui::SetCursorPos(ImVec2(20.0, 50.0));
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(20.0, 20.0));
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.0f, 0.0f, 0.5f));
			ImGui::BeginChild("License", ImVec2(475, 310), true);
			ImGui::PushTextWrapPos(ImGui::GetContentRegionAvail().x);
			// Section: Information Collected
			ImGui::Text("Information Collected:");
			ImGui::TextWrapped("When you participate in our beta program, we collect certain information about your system specifications. This may include but is not limited to:");
			ImGui::BulletText("Operating system");
			ImGui::BulletText("Hardware details");
			ImGui::BulletText("Flight simulator configuration");

			ImGui::Separator();

			// Section: Purpose of Data Collection
			ImGui::Text("Purpose of Data Collection:");
			ImGui::TextWrapped(
				"We collect this information solely for the purpose of enhancing and optimizing our beta program. Understanding your system specifications helps us identify potential issues, improve compatibility, and deliver a better user experience.");

			ImGui::Separator();

			// Section: Data Protection
			ImGui::Text("Data Protection:");
			ImGui::TextWrapped(
				"All collected data is treated with the utmost confidentiality. We implement robust encryption measures to safeguard your system specs from unauthorized access, ensuring the security and privacy of your information.");

			ImGui::Separator();

			// Section: Third-Party Access
			ImGui::Text("Third-Party Access:");
			ImGui::TextWrapped("We do not share your system specifications with any third parties under any circumstances.");

			ImGui::Separator();

			// Section: Data Retention
			ImGui::Text("Data Retention:");
			ImGui::TextWrapped(
				"We retain your system specs only for the duration of which you are in the beta program. At any time, you may request that we remove your data; this will, however, result in removal from the beta program.");

			ImGui::Separator();

			// Section: User Control
			ImGui::Text("User Control:");
			ImGui::TextWrapped(
				"You have the right to access, modify, or request the deletion of your system specs. You can exercise these rights by contacting us through Discord. Please note that removal of your data will result in removal from the beta program.");

			ImGui::Separator();

			// Section: Consent
			ImGui::Text("Consent:");
			ImGui::TextWrapped("By participating in our beta program, you consent to the collection and processing of your system specifications as outlined in this privacy policy.");

			ImGui::Separator();

			// Section: Changes to Privacy Policy
			ImGui::Text("Changes to Privacy Policy:");
			ImGui::TextWrapped("We reserve the right to update this privacy policy to reflect changes in our data practices. Users will be notified of any significant modifications.");

			ImGui::Separator();

			// Section: For Non-Beta Users
			ImGui::Text("For Non-Beta Users:");

			ImGui::Text("Data Collection:");
			ImGui::TextWrapped(
				"If you do not participate in our beta program, we do not collect any personal or system-specific information. The only data collected may be non-personally identifiable information such as usage statistics, crash reports, and other anonymized metrics that help improve the application.");

			ImGui::Separator();

			// Section: Purpose of Data Collection for Non-Beta Users
			ImGui::Text("Purpose of Data Collection:");
			ImGui::TextWrapped("This non-personal information is collected to enhance the overall functionality and performance of the application, ensuring a better user experience.");

			ImGui::Separator();

			// Section: Data Protection for Non-Beta Users
			ImGui::Text("Data Protection:");
			ImGui::TextWrapped("Any data collected is anonymized and cannot be traced back to individual users. We implement robust security measures to protect this information.");

			ImGui::Separator();

			// Section: Third-Party Access for Non-Beta Users
			ImGui::Text("Third-Party Access:");
			ImGui::TextWrapped("We do not share any collected data with third parties under any circumstances.");

			ImGui::Separator();

			// Section: User Control for Non-Beta Users
			ImGui::Text("User Control:");
			ImGui::TextWrapped("You have the right to opt out of data collection for usage statistics and crash reports. This can be done through the application settings.");

			ImGui::Separator();

			// Section: Consent for Non-Beta Users
			ImGui::Text("Consent:");
			ImGui::TextWrapped("By using our application, you consent to the collection and processing of anonymized data as outlined in this privacy policy.");

			ImGui::Separator();

			// Section: Changes to Privacy Policy for Non-Beta Users
			ImGui::Text("Changes to Privacy Policy:");
			ImGui::TextWrapped("We reserve the right to update this privacy policy to reflect changes in our data practices. Users will be notified of any significant modifications.");
			ImGui::PopTextWrapPos();
			ImGui::EndChild();
			ImGui::PopStyleVar();
			ImGui::PopStyleColor();


			ImGui::SetCursorPos(PredefinedCursorPositions::bottomLeftButton);
			if (ImGui::Button("Exit")) {
				Walnut::Application::Get().Close();
				// TODO: show popup confirming exit if the page anything but the first page
			}

			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightSupportingButton);
			if (ImGui::Button("Back")) {
				PrevPage();
			}

			if (!accepted) {
				ImGui::BeginDisabled();
			}
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightButton);
			if (ImGui::Button("Next")) {
				NextPage();
			}

			if (!accepted) {
				ImGui::EndDisabled();
			}
		}
		break;
		case Page::Path: {
			ImGui::Text("Path");
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomLeftButton);
			if (ImGui::Button("Exit")) {
				Walnut::Application::Get().Close();
				// TODO: show popup confirming exit if the page anything but the first page
			}

			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightSupportingButton);
			if (ImGui::Button("Back")) {
				PrevPage();
			}
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightButton);
			if (ImGui::Button("Next")) {
				NextPage();
			}
		}
		break;
		case Page::Download: {
			ImGui::Text("Downloading");


			ProgressBar pb(255.0, 255.0, 200.0, 40.0);
			pb.UpdateProgress(percentage);
			ImDrawList *drawList = ImGui::GetWindowDrawList();
			pb.RenderProgressBar(drawList);

			if (percentage < 100.0f) {
				percentage += 0.1;
			}


			ImGui::SetCursorPos(PredefinedCursorPositions::bottomLeftButton);
			if (ImGui::Button("Exit")) {
				Walnut::Application::Get().Close();
				// TODO: show popup confirming exit if the page anything but the first page
			}
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightSupportingButton);
			if (ImGui::Button("Back")) {
				PrevPage();
			}
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightButton);
			if (ImGui::Button("Next")) {
				NextPage();
			}
		}
		break;
		case Page::Complete: {
			ImGui::Text("Complete");
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightSupportingButton);
			if (ImGui::Button("Back")) {
				PrevPage();
			}
			ImGui::SetCursorPos(PredefinedCursorPositions::bottomRightButton);
			if (ImGui::Button("Finish")) {
				Walnut::Application::Get().Close();
			}
		}
		break;
		default:
			break;
	}
}

Pages::Page Pages::Pages::intToPage(int page) {
	switch (page) {
		case 0: return Page::Welcome;
		case 1: return Page::License;
		case 2: return Page::Path;
		case 3: return Page::Download;
		case 4: return Page::Complete;
		default: return Page::Welcome;
	}
}
